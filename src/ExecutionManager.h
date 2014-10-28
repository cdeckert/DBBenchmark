/*
 * ExecutionManager.h
 *
 *  Created on: Oct 9, 2014
 *      Author: root
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

namespace DBBenchmark {

class ExecutionManager {
public:

	ExecutionManager();
	virtual ~ExecutionManager();

	void start();
	DBTest::ATest initalizeThread(struct HDDTest::TestThread*);
	HDDTest::ConfigGenerator initalizeLayout();

private:
	std::vector<DBTest::ATest> backgroundThreads;
	DBTest::ATest mainThread;
	void startBackgroundTest();
};

} /* namespace DBBenchmark */

#endif /* DBTESTING_SRC_EXECUTIONMANAGER_H_ */
