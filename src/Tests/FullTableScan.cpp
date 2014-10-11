/*
 * FullTableScan.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#include "FullTableScan.h"

namespace DBTest {

FullTableScan::FullTableScan() {
	// TODO Auto-generated constructor stub

}

FullTableScan::~FullTableScan() {
	// TODO Auto-generated destructor stub
}

void FullTableScan::executeTest()
{
	std::cout << "Valid";
	openDisk("/dev/sdb");
	speedUpDisk();

	std::cout << "Valid:::"<< isDiskValid() << std::endl;
	//std::cout << "relation"<< relation->size();


	std::cout << relation;




	for(std::vector<struct HDDTest::extent>::iterator it = relation->begin(); it != relation->end(); ++it)
	{
		try
		{
			unsigned long long int start = (it->start);
			readExtent(start);
		}
		catch(const std::exception &e){}
	}

	std::cout << "DONE";

}

} /* namespace DBTest */
