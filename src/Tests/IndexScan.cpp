/*
 * IndexScan.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "IndexScan.h"
#include "../Util/Progressbar.h"

namespace HDDTest
{

IndexScan::IndexScan(std::string name, std::string layoutName, Layout * layout, Disk *disk, Relationship *relationship, double sleepTime) : ATest(name, layoutName, layout, disk, relationship, sleepTime)
{
	std::cout << this->name <<std::endl;
}


void IndexScan::executeTestAlgorithm()
{
	int iterations = 20;
	uint64_t stepSize = (this->relationship->getNoOfExtents() * layout->getExtentSizeInPages()) / iterations;

	if (stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData = 0;


	Progressbar *progress = new Progressbar("Index Scan - Speed",  stepSize * iterations);


	if (isMain)
	{
		this->log->start();
	}
	uint64_t numberOfLoggedIterations = 0;
	while(numberOfLoggedIterations < stepSize * iterations)
	{

		this->disk->readPage(this->relationship->getRandomPage());
		processedData += layout->getPageSizeInKB();



		if (!this->runs) return;
		if(numberOfLoggedIterations % stepSize == 0)
		{
			this->log->stop(processedData);
		}
		numberOfLoggedIterations++;
		progress->add(1);

		this->sleep();


	}
}

IndexScan::~IndexScan()
{}

} /* namespace HDDTest */
