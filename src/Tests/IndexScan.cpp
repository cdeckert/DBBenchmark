/*
 * IndexScan.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#include "IndexScan.h"

namespace DBTest {

IndexScan::IndexScan() {
	// TODO Auto-generated constructor stub

}

IndexScan::~IndexScan() {
	// TODO Auto-generated destructor stub
}

void IndexScan::testAlgorithm()
{
	unsigned long long int i = 0;
	while(i < getNumberOfPages())
	{
		i = i+8;
		startTimer();
		for(unsigned long long int j = 0; j < i; j++)
		{
			writePage(getRandomPage());
		}
		writeLog(i);
		std::cout << getTime() << std::endl;
	}
}

} /* namespace HDDTest */
