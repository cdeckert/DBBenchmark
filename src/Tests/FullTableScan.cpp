/*
 * FullTableScan.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#include "FullTableScan.h"

namespace HDDTest {

FullTableScan::FullTableScan(std::string name, Disk* disk, Relationship* relationship) : ATest(name, disk, relationship){}




void FullTableScan::executeTestAlgorithm()
{
	uint64_t processedData;
	if(isMain)
	{
		this->log->start();
	}
	do
	{
		this->disk->readExtent(this->relationship->getNextExtent());
		if(!this->runs) return;
	}
	while(this->relationship->isNextExtent());

	if(isMain)
	{
		this->log->stop(processedData);
	}
}

FullTableScan::~FullTableScan() {
	// TODO Auto-generated destructor stub
}

} /* namespace HDDTest */
