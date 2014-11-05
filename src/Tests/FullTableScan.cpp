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
		uint64_t extentStart = this->getNextExtent();
		do{
			if(getDisk() == -1) break;
			this->readExtent(extentStart*1024);
			extentStart = this->getNextExtent();
		}while(this->isNextExtent());
	}
	storeMeasurement();
	writeTestLog();


}


} /* namespace DBTest */
