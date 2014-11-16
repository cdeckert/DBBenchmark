/*
 * TransactionLog.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: root
 */

#include "TransactionLog.h"

namespace HDDTest {

TransactionLog::TransactionLog(std::string name, Disk *disk, Relationship *relationship) : ATest(name, disk, relationship) {}

TransactionLog::~TransactionLog() {
	// TODO Auto-generated destructor stub
}

void TransactionLog::executeTestAlgorithm()
{
	do
		{
			this->disk->readExtent(this->relationship->getNextExtent());
			if (!this->runs) return;
		}
		while (this->relationship->isNextExtent());
}

} /* namespace HDDTest */
