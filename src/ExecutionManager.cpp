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
	configurator.fetchConfigurations();

}

ExecutionManager::~ExecutionManager()
{
	// TODO Auto-generated destructor stub
}




DBTest::ATest ExecutionManager::initalizeSingleThread(struct HDDTest::TestThread threadSettings, std::string device)
{
	DBTest::ATest aTestThread;

	// switch based on thread setting
	aTestThread = DBTest::FullTableScan();




	aTestThread.setDevice(device);
	return aTestThread;
}

void ExecutionManager::initalizeAllThreads(struct HDDTest::TestRun testRun, std::string device)
{
	// initalize main Thread
	mainThread = initalizeSingleThread(testRun.mainThread, device);

	// initalize background Threads
	this->backgroundThreads.clear();
	for (struct HDDTest::TestThread aThreadConfiguration : testRun.backgroundThreads)
	{
		this->backgroundThreads.push_back(this->initalizeSingleThread(aThreadConfiguration, device));
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
		bg.stopThread();
	}
}


void ExecutionManager::executeTestRuns(struct HDDTest::LayoutSettings layoutSetting, std::string device)
{
	HDDTest::Layout layout = HDDTest::Layout();
	layout.diskStart = 0;
	layout.pageSizeInKB = layoutSetting.pageSizeInKB;
	layout.extentSizeInPages = layoutSetting.pagesPerExtent;
	layout.createRelationships(layoutSetting.relationships);
	// for each test run
	std::vector<struct HDDTest::TestRun> testRuns = layoutSetting.testRuns;
	std::cout << layoutSetting.mode;
	for (struct HDDTest::TestRun aTestRun : testRuns)
	{

		//HDDTest::ConfigGenerator config = initalizeLayout();

		// initalize all threads
		this->initalizeAllThreads(aTestRun, device);

		// start all background threads
		this->startBackgroundTest();

		// start main thread and wait for them
		this->mainThread.start();

		// terminate all background threads
		this->terminateBackgroundThreads();

	}
}



void ExecutionManager::executeAllTestWithAllConfigurations()
{
	// execute tests for all specified devices
	for (std::string  device : configurator.configuration.devices)
	{
		// execute all test runs
		this->executeTestRuns(configurator.configuration.layout, device);
	}
}

} /* namespace DBBenchmark */
