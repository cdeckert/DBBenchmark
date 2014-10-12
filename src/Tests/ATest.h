/*
 * ATest.h
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#ifndef DBTESTING_SRC_ATEST_H_
#define DBTESTING_SRC_ATEST_H_
#define _LARGEFILE64_SOURCE
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


using namespace std;
namespace DBTest {

class ATest {
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
	void setLayout(std::vector<struct HDDTest::extent>*);
	void startTimer();
	long long int getTime();
	double getMbPerSec();

	int numberOfIterations;
	void execute();

	unsigned long long int getNumberOfPages();
	unsigned long long int getNumberOfExtents();

	unsigned long long int getRandomPage();

	void writeLog(unsigned long long int);


	bool isEndless;
	std::vector<struct HDDTest::extent> *relation;
	virtual void testAlgorithm();

private:

	int disk;
	int extentSize;
	int pageSize;
	char* pageBuffer;
	char* extentBuffer;
	timespec startTime;
	long long int executionSize;

	void init_rand();
	//std::ofstream log;
};

} /* namespace DBTest */

#endif /* DBTESTING_SRC_ATEST_H_ */
