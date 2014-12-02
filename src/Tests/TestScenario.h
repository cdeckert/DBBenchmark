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
#include "IndexWrite.h"
#include "TransactionLog.h"
#include <iostream>
#include <string>

namespace HDDTest
{

class TestScenario
{
public:
	TestScenario(std::string, std::vector<std::string> *, std::string, Layout *, TestSettings, std::vector<TestSettings>);
	virtual ~TestScenario();
	void run();
	int getNumberOfTests();

private:
	std::string name;
	std::vector<std::string> *diskPaths;
	std::unordered_map<std::string, Layout *> *layouts;

	struct TestSettings mainThreadSettings;
	std::vector<struct TestSettings> backgroundThreadsSettings;

	ATest *initTest(struct TestSettings);

	std::string layoutName;
	Layout * layout;

};

} /* namespace HDDTest */

#endif /* SRC_TESTS_TESTSCENARIO_H_ */
