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
	uint64_t stepSize = (this->relationship->extents.size() * 8) / iterations;

	if (stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData = 0;


	Progressbar *progress = new Progressbar("Index Write", (iterations + 1)*iterations / 2 * stepSize);

	for (int i = 0; i < iterations; i++)
	{
		if (isMain)
		{
			this->log->start();
		}
		processedData = 0;

		for (uint64_t j = 0; j < i * stepSize; j++)
		{
			this->disk->writePage(this->relationship->getRandomPage());
			processedData += layout->getPageSizeInKB();
			if (!this->runs) return;
			progress->add(1);
			this->sleep();
		}
		if (isMain)
		{
			this->log->stop(processedData);
		}


		this->sleep();
	}

}

IndexWrite::~IndexWrite()
{}

} /* namespace HDDTest */
