//============================================================================
// Name        : DBBenchmark.cpp
// Author      : Chris
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include "Util/Configurator.h"
#include "Tests/TestScenario.h"
int main()
{
	// read configuration file
	HDDTest::Configurator *config = new HDDTest::Configurator();
	std::vector<HDDTest::TestScenario *> *testScenarios = config->getTestScenarios();

	for (HDDTest::TestScenario *t : *testScenarios)
	{
		t->run();
	}
	//while (true) {}
	system("./update.sh");
	return 0;
}
