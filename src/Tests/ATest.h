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
#include "../Util/Log.h"
#include <atomic>
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
	ATest(std::string, Disk*, Relationship*);
	virtual ~ATest();
	void start();
	virtual void executeTestAlgorithm();
	void sleep();
	DBUtil::Log* log;
protected:

	Relationship* relationship;
	Disk* disk;
	std::atomic<bool> runs;

private:





};
}/* namespace HDDTest */

#endif /* SRC_TESTS_ATEST_H_ */
