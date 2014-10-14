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
	startTimer();
	for(int iteration = 0; iteration< numberOfIterations; iteration++)
	{
		for(std::vector<struct HDDTest::extent>::iterator it = relation->begin();
				it != relation->end(); it++)
		{
			unsigned long long int start = (it->start);
			readExtent(start);
		}
	}

	std::cout << getTime() /1000000000. / numberOfIterations << ":" << getMbPerSec() / numberOfIterations << std::endl;

}


} /* namespace DBTest */
