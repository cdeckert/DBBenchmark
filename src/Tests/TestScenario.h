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

namespace HDDTest {

class TestScenario
{
public:
	TestScenario(std::vector<std::string*>*, std::unordered_map<std::string, Layout*>*);
	virtual ~TestScenario();
	void run();

private:
	std::vector<std::string*> *diskPaths;
	std::unordered_map<std::string, Layout*> *layouts;

	ATest *mainThread;
	std::vector<ATest*>*backgroundThreads;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_TESTSCENARIO_H_ */
