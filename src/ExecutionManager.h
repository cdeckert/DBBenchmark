/*
 * ExecutionManager.h
 *
 */

#ifndef DBTESTING_SRC_EXECUTIONMANAGER_H_
#define DBTESTING_SRC_EXECUTIONMANAGER_H_

#include <thread>
#include "Layout/ConfigGenerator.h"
#include "Configurator.h"
#include "Tests/LogWriter.h"
#include "Tests/FullTableScan.h"
#include "Tests/IndexScan.h"
#include "Tests/ATest.h"

namespace DBBenchmark
{

class ExecutionManager
{
public:

	ExecutionManager();
	virtual ~ExecutionManager();

	void executeAllTestWithAllConfigurations();
	DBTest::ATest initalizeSingleThread(struct HDDTest::TestThread, std::string);
	HDDTest::ConfigGenerator initalizeLayout();

private:
	std::vector<DBTest::ATest> backgroundThreads;
	DBTest::ATest mainThread;
	void startBackgroundTest();
	HDDTest::Configurator configurator;
	void initalizeAllThreads(struct HDDTest::TestRun, std::string);
	void executeTestRuns(struct HDDTest::LayoutSettings, std::string);
	void terminateBackgroundThreads();
};

} /* namespace DBBenchmark */

#endif /* DBTESTING_SRC_EXECUTIONMANAGER_H_ */
