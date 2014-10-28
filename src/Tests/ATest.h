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
#include "../Layout/ConfigGenerator.h"
#include <fstream>

using namespace std;
namespace DBTest
{

struct measurement
{
	unsigned long long int size;
	unsigned long long int duration;
	double mbPerSec;

};

class ATest
{
public:
	ATest();
	virtual ~ATest();

	void start();
	void virtual startAsThread();
	void writePage(unsigned long long int);
	void writeExtent(unsigned long long int);
	void readPage(unsigned long long int);
	void readExtent(unsigned long long int);
	void openDisk(std::string);
	bool isDiskValid();
	void setExtentSize(int);
	void setPageSize(int);
	void speedUpDisk();
	void setLayout(std::vector<struct HDDTest::extent> *);
	void startTimer();
	long long int getTime();
	double getMbPerSec();

	//void

	void cleanDBCache();

	int numberOfIterations;
	void execute();

	unsigned long long int getNumberOfPages();
	unsigned long long int getNumberOfExtents();

	unsigned long long int getRandomPage();

	void storeMeasurement();

	void writeTestLog();


	bool isEndless;
	std::vector<struct HDDTest::extent> *relation;
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

private:

	int disk;
	int extentSize;
	int pageSize;
	char *pageBuffer;
	char *extentBuffer;
	timespec startTime;
	unsigned long long int executionSize;
	int sleepTime;
	std::string device;
	bool terminateThread = false;
	std::thread* theThread;


	void debug(std::string);

	std::vector<struct measurement> *measurements;

	void init_rand();

};

} /* namespace DBTest */

#endif /* DBTESTING_SRC_ATEST_H_ */
