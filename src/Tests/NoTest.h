/*
 * NoTest.h
 *
 *  Created on: Oct 29, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_NOTEST_H_
#define SRC_TESTS_NOTEST_H_
#include "ATest.h"

namespace DBTest {

class NoTest : public ATest
{
public:
	NoTest();
	virtual ~NoTest();
	void testAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_NOTEST_H_ */

