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
	unsigned long long int i = 1;
	while(i < getNumberOfPages())
	{
		i = i*2;
		cleanDBCache();
		startTimer();
		for(int iteration = 0; iteration< numberOfIterations; iteration++)
		{
			for(unsigned long long int j = 0; j < i; j++)
			{
				readPage(getRandomPage());
			}
		}
		//writeLogFile(i);
		std::cout << i << ":" << getTime() /1000000000. / numberOfIterations << ":" << getMbPerSec() / numberOfIterations << std::endl;
	}
}
}
