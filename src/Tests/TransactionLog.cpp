/*
 * TransactionLog.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: root
 */

#include "TransactionLog.h"

namespace HDDTest {

TransactionLog::TransactionLog(std::string name, Disk *disk, Relationship *relationship) : ATest(name, disk, relationship)
{
	this->initSleep(100);
}

TransactionLog::~TransactionLog() {
	// TODO Auto-generated destructor stub
}

void TransactionLog::executeTestAlgorithm()
{
	int logSize = 0;
	this->disk->writeExtent(this->relationship->getNextExtent());
	while(true)
	{
		if (!this->runs) return;
		if(this->relationship->isNextExtent())
		{
			if(logSize < relationship->pagesPerExtent)
			{
				logSize += (rand() % relationship->pagesPerExtent);
				this->disk->readExtent(this->relationship->getPrevExtent());
				this->disk->writeExtent(this->relationship->getNextExtent());
			}else
			{
				logSize = 0;
				this->relationship->getNextExtent();
			}
			if (!this->runs) return;
			sleep();
			if (!this->runs) return;



		}
		else
		{
			this->relationship->setNextExtent(1);
		}
	}
}

} /* namespace HDDTest */
