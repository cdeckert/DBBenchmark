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

using namespace std;
using namespace rapidjson;
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
	void startAsThread();
	void writePage(unsigned long long int);
	void writeExtent(unsigned long long int);
	void readPage(unsigned long long int);
	void readExtent(unsigned long long int);
	void openDisk(std::string);
	bool isDiskValid();
	void setExtentSize(int);
	void setPageSize(int);
	void speedUpDisk();
	void startTimer();
	long long int getTime();
	double getMbPerSec();

	std::string relationshipName;

	//void

	void cleanDBCache();

	int numberOfIterations;
	void execute();


	unsigned long long int getRandomPage();
	unsigned long long int getRandomExtent();
	unsigned long long int getNextExtent();

	void storeMeasurement();

	string writeTestLog();


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
	unsigned long long int executionSize;
	int sleepTime;
	string device;

	thread *theThread;


	void debug(std::string);

	vector<struct measurement> *measurements;

	void init_rand();

};





} /* namespace DBTest */

#endif /* DBTESTING_SRC_ATEST_H_ */
