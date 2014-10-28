/*
 * IndexScan.h
 *
 */

#ifndef SRC_TESTS_INDEXSCAN_H_
#define SRC_TESTS_INDEXSCAN_H_
#include "ATest.h"

namespace DBTest
{

class IndexScan : public ATest
{
public:
	IndexScan();
	virtual ~IndexScan();

	void testAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_INDEXSCAN_H_ */
