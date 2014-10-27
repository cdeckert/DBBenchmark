/*
 * ExecutionManager.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#include "ExecutionManager.h"
#include "Tests/LogWriter.h"
#include "Tests/FullTableScan.h"
#include "Tests/IndexScan.h"
#include "Configurator.h"


namespace DBBenchmark {

ExecutionManager::ExecutionManager() {
	// TODO Auto-generated constructor stub

}

ExecutionManager::~ExecutionManager() {
	// TODO Auto-generated destructor stub
}

HDDTest::ConfigGenerator ExecutionManager::initalizeLayout()
{
	// hdd starts at 0
		unsigned long long int size_start = 0;
		// spreading of relationship table
		unsigned long long int size_spread = 1024 * 1024 * 5; // kb
		// size of a single extent
		unsigned long long int size_extent = 64;
		// size of a single page
		unsigned long long int size_page = 8;

		enum HDDTest::mode_readMode readMode;
		enum HDDTest::mode_extentDistribution extentDistribution;

		std::string device = "/dev/sde";
		// define read mode: ORDERED or UNORDERED
		readMode = HDDTest::ORDERED;
		// distribution: EQUALLY or ED_RANDOM
		extentDistribution = HDDTest::EQUALLY;
		char no_of_relations = 2;
		char relation_distribution[] = {1, 1}; // standard distribution of the relations


		/*if(argc <= 4) {
			std::cout << "Enter device address: " << std::flush;
			std::cin >> device;
		} else {
			device = std::string(argv[1]);
			readMode = (atoi(argv[2]) == 0) ? HDDTest::ORDERED : HDDTest::UNORDERED;
			extentDistribution = (atoi(argv[3]) == 0) ? HDDTest::EQUALLY : HDDTest::ED_RANDOM;
			no_of_relations = atoi(argv[4]);
		}*/

		HDDTest::ConfigGenerator confGen = HDDTest::ConfigGenerator(
											   size_start, size_spread,
											   size_extent, size_page, readMode,
											   extentDistribution, no_of_relations, relation_distribution);
		// generate configuration
		confGen.generate();

		return confGen;
}



void ExecutionManager::start()
{
	HDDTest::ConfigGenerator config = initalizeLayout();


	HDDTest::Configurator configurator = HDDTest::Configurator();

	configurator.fetchConfigurations();

	// for each configuration do

	// for each thread within the configuration




	DBTest::FullTableScan tableScan = DBTest::FullTableScan();
	//tableScan.isEndless = true;
	tableScan.setExtentSize(64);
	tableScan.setLayout(config.getExtentLocationsOfRel(1));
	tableScan.startAsThread();

	std::cout << std::endl << "INDEX" << std::endl;
	DBTest::IndexScan index = DBTest::IndexScan();
	index.setExtentSize(64);
	index.setLayout(config.getExtentLocationsOfRel(1));
	index.start();


	std::terminate();

}

} /* namespace DBBenchmark */
