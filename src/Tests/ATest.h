/*
 * TestExecutor.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

<<<<<<< HEAD
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
=======
#ifndef SRC_TESTS_ATEST_H_
#define SRC_TESTS_ATEST_H_

#include "../Util/Disk.h"
#include "../Layout/Relationship.h"
#include "../Util/Log.h"
#include <atomic>
namespace HDDTest
>>>>>>> release/MoRelease
{
struct TestSettings
{
<<<<<<< HEAD
	uint64_t size;
	uint64_t duration;
	double mbPerSec;
=======
	std::string name;
	std::uint64_t sleep;
	std::string relationship;
>>>>>>> release/MoRelease

};

class ATest
{
public:
	std::string name;
	std::atomic<bool> isMain;
	ATest(std::string, Disk*, Relationship*);
	virtual ~ATest();
	void start();
<<<<<<< HEAD
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
=======
	virtual void executeTestAlgorithm();
	void sleep();
	DBUtil::Log* log;
protected:
>>>>>>> release/MoRelease

	Relationship* relationship;
	Disk* disk;
	std::atomic<bool> runs;

private:


<<<<<<< HEAD
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
=======

>>>>>>> release/MoRelease


};
}/* namespace HDDTest */

#endif /* SRC_TESTS_ATEST_H_ */
