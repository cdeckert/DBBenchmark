/*
 * IndexWrite.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "IndexWrite.h"
#include "../Util/Progressbar.h"

namespace HDDTest
{

IndexWrite::IndexWrite(std::string name, std::string layoutName, Layout * layout, Disk *disk, Relationship *relationship, double sleepTime) : ATest(name, layoutName, layout, disk, relationship, sleepTime) {}


void IndexWrite::executeTestAlgorithm()
{
	int iterations = 20;
	uint64_t stepSize = (this->relationship->getNoOfExtents() * layout->getExtentSizeInPages()) / iterations;

	if (stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData = 0;


	Progressbar *progress = new Progressbar("Index Write", iterations * stepSize);

	if (isMain) {
		this->log->start();
	}

	processedData = 0;
	for (uint64_t j = 0; j < iterations * stepSize; j++)
	{
		this->disk->writePage(this->relationship->getRandomPage());
		processedData += layout->getPageSizeInKB();
		if (!this->runs) return;

		if (isMain && j % iterations == 0) {
			this->log->stop(processedData);
		}
		progress->add(1);
		this->sleep();
	}
	if (isMain) {
		this->log->stop(processedData);
	}

}

IndexWrite::~IndexWrite()
{}

} /* namespace HDDTest */
