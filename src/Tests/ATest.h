/*
 * TestExecutor.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_ATEST_H_
#define SRC_TESTS_ATEST_H_

#include "../Util/Disk.h"
#include "../Layout/Relationship.h"
#include "../Layout/Layout.h"
#include "../Util/Log.h"
#include <atomic>
#include <thread>
#include <time.h>

namespace HDDTest
{
struct TestSettings
{
	std::string name;
	std::uint64_t sleep;
	std::string relationship;

};



class ATest
{
public:
	std::string name;
	std::atomic<bool> isMain;
	ATest(std::string, std::string, Layout *, Disk *, Relationship *);
	virtual ~ATest();
	void start();
	virtual void executeTestAlgorithm();
	void sleep();
	void startBackground();
	DBUtil::Log *log;
	void initSleep(double);
protected:
	struct timespec tv;
	Relationship *relationship;
	Disk *disk;
	std::atomic<bool> runs;
	std::string layoutName;
	Layout * layout;

private:





};
}/* namespace HDDTest */

#endif /* SRC_TESTS_ATEST_H_ */
