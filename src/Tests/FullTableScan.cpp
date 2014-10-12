/*
 * FullTableScan.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#include "FullTableScan.h"
#include <sys/time.h>

namespace DBTest {

FullTableScan::FullTableScan() {
	// TODO Auto-generated constructor stub

}

FullTableScan::~FullTableScan() {
	// TODO Auto-generated destructor stub
}

void FullTableScan::testAlgorithm()
{
	for(std::vector<struct HDDTest::extent>::iterator it = relation->begin();
			it != relation->end(); it++)
	{
		unsigned long long int start = (it->start);
		readExtent(start);
	}
}


} /* namespace DBTest */
