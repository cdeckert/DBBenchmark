/*
 * IndexScan.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "IndexScan.h"

namespace HDDTest
{

IndexScan::IndexScan(std::string name, Disk* disk, Relationship* relationship) : ATest(name, disk, relationship){}


void IndexScan::executeTestAlgorithm()
{


	uint64_t stepSize = (this->relationship->extents.size() * 8) / 200;

	if(stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData = 0;

	for(int i = 0; i < 200; i++)
	{
		this->log->start();
		processedData = 0;

		for(uint64_t j = 0; j < (1+i) * stepSize; j = j+stepSize)
		{
			std::cout << "execute" << stepSize << disk->path;
			std::cout.flush();
			this->disk->readPage(this->relationship->getRandomPage());
			processedData += 8; // to-do
			if(!this->runs) return;
		}
		this->log->stop(processedData);
		this->sleep();
	}

}

IndexScan::~IndexScan()
{}

} /* namespace HDDTest */
