/*
 * TestExecutor.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "ATest.h"

namespace HDDTest
{

ATest::ATest(std::string name, std::string layoutName, Disk *disk, Relationship *relationship)
{
	this->name = name;
	this->disk = disk;
	this->relationship = relationship;
	this->log = new DBUtil::Log();
	this->runs = true;
	this->isMain = false;
	this->initSleep(0);
	this->layoutName = layoutName;
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

void ATest::initSleep(double sleepTime)
{
		tv.tv_sec = (time_t) sleepTime;
		tv.tv_nsec = (long) ((sleepTime - tv.tv_sec) * 1e+9);
}

void ATest::sleep()
{
	nanosleep (&tv, &tv);
}

void ATest::startBackground()
{
	std::thread t1(&ATest::start, this);
	std::cout << "thread id: " << t1.get_id() << "\n";
	t1.detach();
	//t1.join();
}

} /* namespace HDDTest */
