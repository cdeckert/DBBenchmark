/*
 * OrderedIndexScan.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_OrderedIndexScan_H_
#define SRC_TESTS_OrderedIndexScan_H_
#include "ATest.h"

namespace HDDTest
{

class OrderedIndexScan : public ATest
{
public:
	OrderedIndexScan(std::string, std::string, Layout *, Disk *, Relationship *, double);
	virtual ~OrderedIndexScan();
	void executeTestAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_OrderedIndexScan_H_ */
