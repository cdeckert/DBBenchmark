/*
 * ATest.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#include "ATest.h"

namespace DBTest {

ATest::ATest() {
	this->isEndless = false;

}

ATest::~ATest() {
	// TODO Auto-generated destructor stub
}

void ATest::setExtentSize(int size)
{
	this->extentSize = size;
	this->extentBuffer = new char[extentSize*1024];
}

void ATest::openDisk(std::string diskPath)
{
	this->disk = open64(diskPath.data(), O_RDWR | O_SYNC);

	if(!isDiskValid())
	{
		std::cout << "Error: Disk permissions";
	}
}

bool ATest::isDiskValid()
{
	std::cout << "Disk: " << disk;
	return (this->disk != -1);
}

void ATest::executeTest()
{
	std::cout << this->isEndless << std::endl;
}

void ATest::start()
{
	if(this->isEndless)
	{
		while(true)
		{
			executeTest();
		}
	}
	else
	{
		executeTest();
	}
}

void ATest::speedUpDisk()
{
	if(isDiskValid())
	{
		lseek64(disk, 0, SEEK_SET);
		lseek64(disk, 0, SEEK_END);
		lseek64(disk, 0, SEEK_SET);
	}
}

void ATest::writeExtent(unsigned long long int start)
{
	lseek64(disk, start, SEEK_SET);
	write(disk, &extentBuffer, extentSize*1024);
}

void ATest::startAsThread()
{
	//this->isEndless = true;
	//std::thread t(&ATest::start, this);

	//t.detach();
	//t.join();
}



} /* namespace DBTest */
