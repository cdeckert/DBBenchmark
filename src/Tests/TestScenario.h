/*
 * TestScenario.h
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_TESTSCENARIO_H_
#define SRC_TESTS_TESTSCENARIO_H_
#include <vector>
#include "../Layout/Layout.h"
#include "../Util/Disk.h"
#include "ATest.h"
#include "IndexScan.h"

namespace HDDTest {

class TestScenario
{
public:
	TestScenario(std::vector<std::string*>*, std::unordered_map<std::string, Layout*>*, TestSettings, std::vector<TestSettings>);
	virtual ~TestScenario();
	void run();
	int getNumberOfTests();

private:
	std::vector<std::string*> *diskPaths;
	std::unordered_map<std::string, Layout*> *layouts;

	struct TestSettings mainThreadSettings;
	std::vector<TestSettings> backgroundThreadsSettings;

	ATest* initTest(struct TestSettings);
	//ATest *mainThread;
	//std::vector<ATest*>*backgroundThreads;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_TESTSCENARIO_H_ */
