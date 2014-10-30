/*
 * WritePages.h
 *
 *  Created on: Oct 30, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_WRITEPAGES_H_
#define SRC_TESTS_WRITEPAGES_H_
#include "ATest.h"

namespace DBTest {

class WritePages : public ATest {
public:
	WritePages();
	virtual ~WritePages();
	void testAlgorithm() override;
};

} /* namespace HDDTest */

#endif /* SRC_TESTS_WRITEPAGES_H_ */
