/**
 * @file DBBenchmark.cpp
 * @Author Christian Deckert (christian.deckert@zentrale2.com)
 * @date October, 2014
 * @brief reads configuration from config.json, generates test scenarios and executes them
 */

#include <iostream>
#include <unistd.h>
#include "Util/Configurator.h"
#include "Tests/TestScenario.h"
int main()
{
	// read configuration file
	HDDTest::Configurator *config = new HDDTest::Configurator();

	// generate test Scenarios
	std::vector<HDDTest::TestScenario *> *testScenarios = config->getTestScenarios();

	// execute testScenararios
	for (HDDTest::TestScenario *t : *testScenarios)
	{
		t->run();
	}
	return 0;
}
