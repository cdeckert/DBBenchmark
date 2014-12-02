/*
 * FullTableScan.h
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_FULLTABLESCAN_H_
#define SRC_TESTS_FULLTABLESCAN_H_

#include "ATest.h"

namespace HDDTest
{

class FullTableScan : public ATest
{
public:
	FullTableScan(std::string, std::string, Layout *, Disk *, Relationship *, double);
	virtual ~FullTableScan();
	void executeTestAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_FULLTABLESCAN_H_ */
