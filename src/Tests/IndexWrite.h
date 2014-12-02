/*
 * IndexWrite.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_INDEXWrite_H_
#define SRC_TESTS_INDEXWrite_H_
#include "ATest.h"

namespace HDDTest
{

class IndexWrite : public ATest
{
public:
	IndexWrite(std::string, std::string, Layout * layout, Disk *, Relationship *, double);
	virtual ~IndexWrite();
	void executeTestAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_INDEXWrite_H_ */
