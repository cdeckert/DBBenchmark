/*
 * ATest.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#include "ATest.h"
#include <stdio.h>

namespace DBTest {

ATest::ATest() {
	this->isEndless = false;
	this->executionSize = 0;
	this->numberOfIterations = 1;
	setPageSize(8);
	setExtentSize(64);
	init_rand();
}

ATest::~ATest() {

}

void ATest::init_rand()
{
	time_t t;

	time(&t);
	srand((unsigned int)t);              /* Zufallsgenerator initialisieren */
}

void ATest::setExtentSize(int size)
{
	this->extentSize = size;
	this->extentBuffer = new char[extentSize*1024];
}

unsigned long long int ATest::getNumberOfPages()
{
	return getNumberOfExtents() * (extentSize/pageSize);
}
unsigned long long int ATest::getNumberOfExtents()
{
	return this->relation->size();
}

unsigned long long int ATest::getRandomPage()
{
	return this->relation->at(rand() % getNumberOfExtents()).start + (rand() % (extentSize/pageSize))*pageSize;
}

void ATest::setPageSize(int size)
{
	this->pageSize = size;
	this->pageBuffer = new char[pageSize*1024];
}

void ATest::openDisk(std::string diskPath)
{
	this->disk = open64(diskPath.data(), O_RDWR | O_SYNC); // | O_DIRECT | O_LARGEFILE);
	perror("OPEN");
	if(!isDiskValid())
	{
		std::cout << "Error: Disk permissions";
	}
}


void ATest::setLayout(std::vector<struct HDDTest::extent>* relation)
{
	this->relation = relation;
}

bool ATest::isDiskValid()
{
	return (this->disk != -1);
}

void ATest::startTimer()
{
	clock_gettime(CLOCK_REALTIME, &startTime);
}

long long int ATest::getTime()
{
	timespec endTime;
	clock_gettime(CLOCK_REALTIME, &endTime);
	return (endTime.tv_sec - startTime.tv_sec)*1000000000 + (endTime.tv_nsec - startTime.tv_nsec) ;
}

void ATest::testAlgorithm()
{
	std::cout << this->isEndless << std::endl;
}

/*void ATest::writeLogFile(unsigned long long int iteration)
{
	log <<iteration << "," << getTime() /1000000000.;
}*/


void ATest::execute()
{
	openDisk("/dev/sdb");
	speedUpDisk();


	testAlgorithm();


}

void ATest::start()
{
	if(this->isEndless)
	{
		while(true)
		{
			execute();
		}
	}
	else
	{
		execute();
	}
}

void ATest::speedUpDisk()
{
	if(isDiskValid())
	{
		lseek64(disk, 0, SEEK_SET);
		lseek64(disk, 0, SEEK_END);
		lseek64(disk, 0, SEEK_SET);
		perror("seek startup");
	}
}

double ATest::getMbPerSec()
{
	return (executionSize/1024.)/(getTime()/1000000000.);
	return 0;
}

void ATest::writeExtent(unsigned long long int start)
{

	lseek64(disk, start*1024, SEEK_SET);
	write(disk, &extentBuffer, extentSize*1024);
	executionSize += extentSize;
}

void ATest::readExtent(unsigned long long int start)
{
	lseek64(disk, start*1024, SEEK_SET);
	read(disk, extentBuffer, extentSize*1024);
	executionSize += extentSize;
}

void ATest::readPage(unsigned long long int start)
{
	lseek64(disk, start*1024, SEEK_SET);
	read(disk, pageBuffer, pageSize*1024);
	executionSize += pageSize;
}

void ATest::writePage(unsigned long long int start)
{
	lseek64(disk, start*1024, SEEK_SET);
	write(disk, pageBuffer, pageSize*1024);
	executionSize += pageSize;
}

void ATest::startAsThread()
{
	//this->isEndless = true;
	//std::thread t(&ATest::start, this);

	//t.detach();
	//t.join();
}



} /* namespace DBTest */
