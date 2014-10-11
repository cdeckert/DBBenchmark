/*
 * ExecutionManager.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#include "ExecutionManager.h"
#include "LogWriter.h"
#include "ConfigReader.h"

namespace DBBenchmark {

ExecutionManager::ExecutionManager() {
	// TODO Auto-generated constructor stub

}

ExecutionManager::~ExecutionManager() {
	// TODO Auto-generated destructor stub
}

void ExecutionManager::start()
{
	DBTest::LogWriter log = DBTest::LogWriter();
	//log.isEndless = true;
	log.start();
}

} /* namespace DBBenchmark */
