/*
 * ATest.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#include "ATest.h"

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;
namespace DBTest
{
int ATest::disk = -1;
ATest::ATest()
{
	this->isEndless = false;
	this->executionSize = 0;
	this->numberOfIterations = 1;
	setPageSize(8);
	setExtentSize(64);
	init_rand();
	sleepTime = 0;

	measurements = new std::vector<measurement>();
}

ATest::~ATest()
{

}

void ATest::init_rand()
{
	time_t t;

	time(&t);
	srand((unsigned int)t);
}


void ATest::setExtentSize(int size)
{
	std::cout << "setExtentSize" << size;
	this->extentSize = size;
	this->extentBuffer = new char[extentSize * 1024];
}

void ATest::setPageSize(int size)
{
	this->pageSize = size;
	this->pageBuffer = new char[pageSize * 1024];
}

/*void ATest::setLayout(std::vector<struct HDDTest::extent> *relation)
{
	this->relation = relation;
}*/
/*
unsigned long long int ATest::getNumberOfExtents()
{
	return this->relation->size();
}

unsigned long long int ATest::getNumberOfPages()
{
	return getNumberOfExtents() * (extentSize / pageSize);
}*/

void ATest::speedUpDisk()
{
	if (isDiskValid())
	{

		lseek64(getDisk(), 0, SEEK_SET);
		read(getDisk(), extentBuffer, extentSize * 1024);
		read(getDisk(), extentBuffer, extentSize * 1024);
		perror("seek startup");
	}
}

double ATest::getMbPerSec()
{
	return (executionSize/1024.) / (getTime() / 1000000000.);
	return 0;
}

void ATest::startTimer()
{
	clock_gettime(CLOCK_REALTIME, &startTime);
}

long long int ATest::getTime()
{
	timespec endTime;
	clock_gettime(CLOCK_REALTIME, &endTime);
	return (endTime.tv_sec - startTime.tv_sec) * 1000000000 + (endTime.tv_nsec - startTime.tv_nsec) ;
}

void ATest::storeMeasurement()
{
	struct measurement tmp;
	tmp.duration = this->getTime() / numberOfIterations;
	tmp.size = this->executionSize / numberOfIterations;
	tmp.mbPerSec = this->getMbPerSec();
	measurements->push_back(tmp);
	this->startTimer();
}


std::string ATest::writeTestLog()
{
	if(!this->isEndless)
	{
	StringBuffer s;
	Writer<StringBuffer> writer(s);
	writer.StartObject();
	writer.String("device");
	writer.String(device.data());
	writer.String("measurements");
	writer.StartArray();
	for (std::vector<struct measurement>::iterator it = this->measurements->begin() ; it != this->measurements->end(); ++it)
	{
		writer.StartObject();
		/*writer.String("relationship");
		writer.StartArray();
		for(std::vector<HDDTest::Extent>::iterator ext = this->layout->getRelationship(this->relationshipName)->extents.begin();
				ext != this->layout->getRelationship(this->relationshipName)->extents.end(); ++ ext)
		{
			writer.Int64(static_cast<unsigned int>((*ext).startKb / 1024));
		}
		writer.EndArray();
		*/writer.String("duration");
		writer.Double(static_cast<double> (it->duration / 1000000000.));
		writer.String("size");
		writer.Double(static_cast<double> (it->size / (1024)));
		writer.String("mbPerSec");
		writer.Double(static_cast<double> (it->mbPerSec));

		writer.EndObject();
	}
	writer.EndArray();
	writer.EndObject();
	std::ofstream json;
	json.open("result.json");
	json << s.GetString();
	json.close();

	debug(s.GetString());




	return s.GetString();

	}
	close(getDisk());
	disk = -1;
	measurements->clear();
	return "";
}
/**
 * Initalize random numbers
 */
/**
 * Sets size of a single extent
 */
/**
 * Makes sure that there is no data in your database cache
 */
void ATest::cleanDBCache()
{
	char *buffer = new char[128 * 1024 * 1024];;
	lseek64(getDisk(), -128 * 1024 * 1024, SEEK_END);
	read(getDisk(), buffer, 128 * 1024 * 1024);
}


/**
 * returns a random Page
 */
unsigned long long int ATest::getRandomPage()
{
	return layout->getRelationship(relationshipName)->getRandomPage();
}

unsigned long long int ATest::getRandomExtent()
{
	return layout->getRelationship(relationshipName)->getRandomExtent();
}

unsigned long long int ATest::getNextExtent()
{
	return layout->getRelationship(relationshipName)->getNextExtent();
}

bool ATest::isNextExtent()
{
	return layout->getRelationship(relationshipName)->isNextExtent();
}


/**
 * opens a disk for a specific disk path
 */
void ATest::openDisk(std::string diskPath)
{
	if(getDisk() == -1)
	{
		setDisk(open64(diskPath.data(), O_RDWR | O_SYNC)); // | O_DIRECT | O_LARGEFILE);
		perror("OPEN");
		if (!isDiskValid())
		{
			std::cout << "Error: Disk permissions";
		}
	}
}

int ATest::getDisk()
{

	if(disk > 0)
	return disk;
	else
	return -1;
}

void ATest::setDisk(int d)
{
	disk = d;
}

/**
 * injecting layout
 */
bool ATest::isDiskValid()
{
	return (getDisk() != -1);
}


void ATest::start()
{
	if (this->isEndless)
	{
		while (true)
		{
			execute();
			if(this->terminateThread)
			{
				break;
			}
		}
	}
	else
	{
		execute();
	}
}

void ATest::execute()
{
	openDisk(this->device);
	speedUpDisk();
	std::cout << "START TEST" << std::endl;
	testAlgorithm();

}

void ATest::testAlgorithm()
{
	std::cout << "wrong Test";
	std::cout << this->isEndless << std::endl;
}

/*void ATest::writeLogFile(unsigned long long int iteration)
{
    log <<iteration << "," << getTime() /1000000000.;
}*/


/**
 * seeks to the end and start of the a disk
 */
void ATest::writeExtent(unsigned long long int start)
{

	lseek64(getDisk(), start * 1024, SEEK_SET);
	write(getDisk(), &extentBuffer, extentSize * 1024);
	executionSize += extentSize;
}

void ATest::readExtent(unsigned long long int start)
{
	lseek64(getDisk(), start*1024, SEEK_SET) ;
	read(getDisk(), extentBuffer, extentSize * 1024);
	executionSize += extentSize;
}

void ATest::readPage(unsigned long long int start)
{

	lseek64(getDisk(), start*1024, SEEK_SET);
	read(getDisk(), pageBuffer, pageSize * 1024);
	executionSize += pageSize;
}

void ATest::writePage(unsigned long long int start)
{
	lseek64(getDisk(), start * 1024, SEEK_SET);
	write(getDisk(), pageBuffer, pageSize * 1024);
	executionSize += pageSize;
}


void ATest::debug(std::string input)
{
	std::cout << input;
}



void ATest::startAsThread()
{
	this->isEndless = true;
	std::thread theThread(&ATest::start, this);
	theThread.detach();
}

void ATest::stopThread()
{

	terminateThread = true;
	theThread->join();
}



} /* namespace DBTest */
