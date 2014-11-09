/*
 * IndexScan.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "IndexScan.h"

namespace HDDTest {

IndexScan::IndexScan(Disk* disk, Relationship* relationship) : ATest(disk, relationship)
{

}


void IndexScan::executeTestAlgorithm()
{


	uint64_t stepSize = (this->relationship->extents.size() * 8) / 200;

	if(stepSize == 0)
	{
		stepSize = 1;
	}

	uint64_t processedData;
	for(int i = 0; i < 200; i++)
	{
		this->log->start();
		processedData = 0;
		for(uint64_t j = 0; j < i*stepSize; j+stepSize)
		{
			this->disk->readPage(this->relationship->getRandomPage());
			processedData += 8;
			if(!this->runs) return;
		}
		this->log->stop(processedData);
		this->sleep();

	}

}

IndexScan::~IndexScan() {
	// TODO Auto-generated destructor stub
}

} /* namespace HDDTest */
