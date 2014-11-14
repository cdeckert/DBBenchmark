/*
 * TestExecutor.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "ATest.h"

namespace HDDTest
{

ATest::ATest(std::string name, Disk *disk, Relationship *relationship)
{
	this->name = name;
	this->disk = disk;
	this->relationship = relationship;
	this->log = new DBUtil::Log();
	this->runs = true;
	this->isMain = false;
}

void ATest::start()
{
	if(isMain)
	{
		std::cout << "MAINTHREAD";
		executeTestAlgorithm();
	}
	else
	{
		while(true)
		{
			std::cout << "BACKGROUND";
			std::cout.flush();
			executeTestAlgorithm();
		}
	}
}
void ATest::executeTestAlgorithm() {}

ATest::~ATest()
{
	delete log;
}

void ATest::sleep()
{
}

void ATest::startBackground()
{
	std::thread t1(&ATest::start, this);
	std::cout << "thread id: " << t1.get_id() << "\n";
	t1.detach();
	//t1.join();
}

} /* namespace HDDTest */
