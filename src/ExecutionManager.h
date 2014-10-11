/*
 * ExecutionManager.h
 *
 *  Created on: Oct 9, 2014
 *      Author: root
 */

#ifndef DBTESTING_SRC_EXECUTIONMANAGER_H_
#define DBTESTING_SRC_EXECUTIONMANAGER_H_

#include <thread>

namespace DBBenchmark {

class ExecutionManager {
public:

	ExecutionManager();
	virtual ~ExecutionManager();

	void start();
};

} /* namespace DBBenchmark */

#endif /* DBTESTING_SRC_EXECUTIONMANAGER_H_ */
