/*
 * IndexScan.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_INDEXSCAN_H_
#define SRC_TESTS_INDEXSCAN_H_
#include "ATest.h"

namespace HDDTest
{

class IndexScan : public ATest
{
public:
	IndexScan(std::string, Disk *, Relationship *);
	virtual ~IndexScan();
	void executeTestAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_INDEXSCAN_H_ */
