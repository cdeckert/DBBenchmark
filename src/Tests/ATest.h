/*
 * ATest.h
 *
 *  Created on: Oct 9, 2014
 *      Author: root
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
#include "../Layout/ConfigGenerator.h"

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
	void speedUpDisk();
	void setLayout(std::vector<struct HDDTest::extent>*);

	bool isEndless;
	std::vector<struct HDDTest::extent>* relation;


private:
	virtual void executeTest();
	int disk;
	int extentSize;
	int pageSize;
	char* pageBuffer;
	char* extentBuffer;

};

} /* namespace DBTest */

#endif /* DBTESTING_SRC_ATEST_H_ */
