/*
 * TestScenario.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#include "TestScenario.h"

namespace HDDTest {

TestScenario::TestScenario(std::vector<std::string*> *diskPaths, std::unordered_map<std::string, Layout*> *layouts)
{
	this->diskPaths = diskPaths;
	this->layouts = layouts;
	this->backgroundThreads = new std::vector<ATest*>();
}

TestScenario::~TestScenario() {
	// TODO Auto-generated destructor stub
}


void TestScenario::run() {
}

} /* namespace HDDTest */
