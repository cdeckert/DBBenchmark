/*
 * FullTableScan.cpp
 *
 */

#include "FullTableScan.h"
#include <sys/time.h>

namespace DBTest
{

FullTableScan::FullTableScan()
{
	// TODO Auto-generated constructor stub

}

FullTableScan::~FullTableScan()
{
	// TODO Auto-generated destructor stub
}

void FullTableScan::testAlgorithm()
{
	cleanDBCache();
	startTimer();
	for (int iteration = 0; iteration < numberOfIterations; iteration++)
	{
		unsigned long long int extentStart = this->getNextExtent();
		do{
			//std::cout << "DEBUG DEBUG::::: " << extentStart;
			this->readExtent(extentStart);
			extentStart = this->getNextExtent();
		}while(this->isNextExtent());
	}
	storeMeasurement();
	writeTestLog();

	std::cout << getTime() / 1000000. / numberOfIterations << ":" << getMbPerSec() / numberOfIterations << std::endl;

}


} /* namespace DBTest */
