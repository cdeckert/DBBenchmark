/*
 * RingBuffer.h
 *
 *  Created on: Nov 15, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_TRANSACTIONLOG_H_
#define SRC_TESTS_TRANSACTIONLOG_H_
#include "ATest.h"

namespace HDDTest {

class TransactionLog  : public ATest
{
public:
	TransactionLog(std::string, std::string, Layout *, Disk *, Relationship *);
	virtual ~TransactionLog();
	void executeTestAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_TRANSACTIONLOG_H_ */
