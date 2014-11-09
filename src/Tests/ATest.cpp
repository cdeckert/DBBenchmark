/*
 * TestExecutor.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "ATest.h"

namespace HDDTest
{

ATest::ATest(std::string name, Disk* disk, Relationship* relationship)
{
	this->name = name;
	this->disk = disk;
	this->relationship = relationship;
	this->log = new DBUtil::Log();
	this->runs = true;
}

void ATest::start()
{
	executeTestAlgorithm();
}
void ATest::executeTestAlgorithm(){}

ATest::~ATest()
{
	// TODO Auto-generated destructor stub
}

void ATest::sleep() {
}

} /* namespace HDDTest */
