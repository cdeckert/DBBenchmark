/*
 * ATest.h
 *
 */

#ifndef DBTESTING_SRC_ATEST_H_
#define DBTESTING_SRC_ATEST_H_
#include <iostream>
#include <thread>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include "../Layout/Layout.h"
#include <cstdint>

namespace DBTest
{

struct measurement
{
	uint64_t size;
	uint64_t duration;
	double mbPerSec;

};

class ATest
{
public:
	ATest();
	virtual ~ATest();

	void start();
	void startAsThread();
	void writePage(uint64_t);
	void writeExtent(uint64_t);
	void readPage(uint64_t);
	void readExtent(uint64_t);
	void openDisk(std::string);
	bool isDiskValid();
	void setExtentSize(int);
	void setPageSize(int);
	void speedUpDisk();
	void startTimer();
	int64_t getTime();
	double getMbPerSec();

	std::string relationshipName;

	//void

	void cleanDBCache();

	int numberOfIterations;
	void execute();


	uint64_t getRandomPage();
	uint64_t getRandomExtent();
	uint64_t getNextExtent();

	void storeMeasurement();

	std::string writeTestLog();


	bool isEndless;
	virtual void testAlgorithm();

	const std::string &getDevice() const
	{
		return device;
	}

	void setDevice(const std::string &device)
	{
		this->device = device;
	}

	void stopThread();
	bool isNextExtent();


	HDDTest::Layout* layout;
	bool terminateThread = false;
	//static int disk;
	static int getDisk();
	static void setDisk(int);
private:


	static int disk;
	int extentSize;
	int pageSize;
	char *pageBuffer;
	char *extentBuffer;
	timespec startTime;
	uint64_t executionSize;
	int sleepTime;
	std::string device;

	std::thread *theThread;


	void debug(std::string);

	std::vector<struct measurement> *measurements;

	void init_rand();

};





} /* namespace DBTest */

#endif /* DBTESTING_SRC_ATEST_H_ */
