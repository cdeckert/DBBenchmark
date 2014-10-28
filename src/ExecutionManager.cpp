/*
 * ExecutionManager.cpp
 *
 */

#include "ExecutionManager.h"




namespace DBBenchmark
{

ExecutionManager::ExecutionManager()
{
	configurator = HDDTest::Configurator();

}

ExecutionManager::~ExecutionManager()
{
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


DBTest::ATest ExecutionManager::initalizeThread(struct HDDTest::TestThread *threadSettings, std::string device)
{
	DBTest::ATest aTestThread;

	// switch based on thread setting
	aTestThread = DBTest::FullTableScan();




	aTestThread.setDevice(device);
	return aTestThread;
}

void ExecutionManager::initalizeThreads(struct HDDTest::TestRun testRun, std::string device)
{
	// initalize main Thread
	mainThread = initalizeThread(testRun.mainThread, device);

	// initalize background Threads
	this->backgroundThreads.clear();
	for (struct HDDTest::TestThread *aThreadConfiguration : testRun.backgroundThreads)
	{
		this->backgroundThreads.push_back(this->initalizeThread(aThreadConfiguration, device));
	}
}


void ExecutionManager::startBackgroundTest()
{
	for (DBTest::ATest bg : backgroundThreads)
	{
		bg.startAsThread();
	}
}

void ExecutionManager::terminateBackgroundThreads()
{
	for (DBTest::ATest bg : backgroundThreads)
	{
		//bg.terminate();
	}
}


void ExecutionManager::executeTestRuns(std::vector<struct HDDTest::TestRun> testRuns, std::string device)
{
	// for each test run
	for (struct HDDTest::TestRun aTestRun : testRuns)
	{
		// initalize all threads
		this->initalizeThreads(aTestRun, device);
		// start all background threads
		this->startBackgroundTest();
		// start main thread and wait for them
		this->mainThread.start();
		// terminate all background threads
		this->terminateBackgroundThreads();

	}
}



void ExecutionManager::start()
{
	configurator.fetchConfigurations();

	HDDTest::ConfigGenerator config = initalizeLayout();

	// execute tests for all specified devices
	for (std::string  device : configurator.configuration.devices)
	{
		// execute all test runs
		this->executeTestRuns(configurator.configuration.testRuns, device);
	}
}

} /* namespace DBBenchmark */
