/*
 * FullTableScan.h
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#ifndef SRC_FULLTABLESCAN_H_
#define SRC_FULLTABLESCAN_H_
#include "ATest.h"


namespace DBTest {

class FullTableScan : public ATest {
public:
	FullTableScan();
	virtual ~FullTableScan();
	void testAlgorithm() override;
};

} /* namespace DBTest */

#endif /* SRC_FULLTABLESCAN_H_ */
