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




DBTest::ATest* ExecutionManager::initalizeSingleThread(struct HDDTest::TestThread threadSettings, std::string device, HDDTest::Layout* layout)
{
	std::cout << "initalized" << std::endl;
	DBTest::ATest* aTestThread;
	// switch based on thread setting
	if(threadSettings.testName == "fullTableScan")
	{
		aTestThread = new DBTest::FullTableScan();
	}
	else if(threadSettings.testName == "indexScan")
	{
		aTestThread = new DBTest::IndexScan();
	}
	else
	{
		aTestThread = new DBTest::NoTest();
	}
	aTestThread->setPageSize(layout->pageSizeInKB);
	aTestThread->setExtentSize(layout->pageSizeInKB * layout->extentSizeInPages);
	aTestThread->layout = layout;
	aTestThread->relationshipName = threadSettings.relationship;
	aTestThread->setPageSize(layout->pageSizeInKB);



	aTestThread->setDevice(device);
	return aTestThread;
}

void ExecutionManager::initalizeAllThreads(struct HDDTest::TestRun testRun, std::string device, HDDTest::Layout* layout)
{
	// initalize main Thread
	mainThread = initalizeSingleThread(testRun.mainThread, device, layout);

	// initalize background Threads
	this->backgroundThreads.clear();
	for (std::vector<struct HDDTest::TestThread>::iterator aThreadConfiguration = testRun.backgroundThreads.begin(); aThreadConfiguration != testRun.backgroundThreads.end(); ++aThreadConfiguration)
	{
		this->backgroundThreads.push_back(this->initalizeSingleThread(*aThreadConfiguration, device, layout));
	}
}


void ExecutionManager::startBackgroundTest()
{
	for (std::vector<DBTest::ATest*>::iterator bg = backgroundThreads.begin(); bg != backgroundThreads.end(); ++bg)
	{
		std::cout << "###########################START BACKGROUND JOB #######################";
		(*bg)->startAsThread();
	}
}

void ExecutionManager::terminateBackgroundThreads()
{
	for (std::vector<DBTest::ATest*>::iterator bg = backgroundThreads.begin(); bg != backgroundThreads.end(); ++bg)
	{
		(*bg)->stopThread();
	}
}


void ExecutionManager::executeTestRuns(struct HDDTest::LayoutSettings layoutSetting, std::string device)
{
	std::cout << "executeTestRuns";
	HDDTest::Layout layout = HDDTest::Layout();
	layout.diskStart = 0;
	layout.pageSizeInKB = layoutSetting.pageSizeInKB;
	layout.extentSizeInPages = layoutSetting.pagesPerExtent;
	layout.createRelationships(layoutSetting.relationships);
	// for each test run
	for (std::vector<struct HDDTest::TestRun>::iterator aTestRun = layoutSetting.testRuns.begin(); aTestRun != layoutSetting.testRuns.end(); ++aTestRun)
	{
		std::cout << "##############################"<< std::endl;

		// initalize all threads
		this->initalizeAllThreads(*aTestRun, device, &layout);

		// start all background threads
		this->startBackgroundTest();

		// start main thread and wait for them
		this->mainThread->start();

		// terminate all background threads
		this->terminateBackgroundThreads();

	}
}



void ExecutionManager::executeAllTestWithAllConfigurations()
{
	try
		{
	// execute tests for all specified devices
	for (std::vector<std::string>::iterator  device = configurator.configuration.devices.begin(); device != configurator.configuration.devices.end(); ++device)
	{
		// execute all test runs
		this->executeTestRuns(configurator.configuration.layout, *device);
	}

	}catch(const std::out_of_range& oor)
	{
		std::cout << "Out of Range error: " << oor.what() << '\n';
	}
}

} /* namespace DBBenchmark */
