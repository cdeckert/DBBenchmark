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

IndexScan::IndexScan(std::string name, Disk* disk, Relationship* relationship) : ATest(name, disk, relationship){}


void IndexScan::executeTestAlgorithm()
{

	int iterations = 20;
	uint64_t stepSize = (this->relationship->extents.size() * 8) / iterations;

	if(stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData = 0;

	Progressbar *progress = new Progressbar("Index Scan", (iterations+1)*iterations/2 * stepSize);

	for(int i = 0; i < iterations; i++)
	{
		this->log->start();
		processedData = 0;

		for(uint64_t j = 0; j < i * stepSize; j++)
		{

			this->disk->readPage(this->relationship->getRandomPage());
			processedData += 8; // to-do
			if(!this->runs) return;
			progress->add(1);
		}
		this->log->stop(processedData);

		this->sleep();
	}

}

IndexScan::~IndexScan()
{}

} /* namespace HDDTest */
