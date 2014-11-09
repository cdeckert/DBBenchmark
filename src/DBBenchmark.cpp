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
int main() {

	// read configuration file
	HDDTest::Configurator *config = new HDDTest::Configurator();
	config->fetchConfiguration();

	std::vector<HDDTest::TestScenario*> testScenarios = HDDTest::TestScenario::generateScenarios(config);



	//DBBenchmark::ExecutionManager manager = DBBenchmark::ExecutionManager();
	//manager.executeAllTestWithAllConfigurations();
	//system("./update.sh");
	return 0;
}
