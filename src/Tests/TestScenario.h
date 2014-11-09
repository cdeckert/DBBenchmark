/*
 * TestScenario.h
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_TESTSCENARIO_H_
#define SRC_TESTS_TESTSCENARIO_H_
#include <vector>
#include "../Util/Configurator.h"

namespace HDDTest {

class TestScenario
{
public:
	TestScenario();
	virtual ~TestScenario();
	static std::vector<TestScenario*> generateScenarios(HDDTest::Configurator*&);
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_TESTSCENARIO_H_ */
