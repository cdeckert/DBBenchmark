/*
 * WritePages.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: root
 */

#include "WritePages.h"

namespace DBTest {

WritePages::WritePages() {
	// TODO Auto-generated constructor stub

}

WritePages::~WritePages() {
	// TODO Auto-generated destructor stub
}


void WritePages::testAlgorithm()
{
	std::cout << "TEST STARTED" << std::endl;
	unsigned long long int i = 1;
	HDDTest::Relationship *r = layout->getRelationship(this->relationshipName);
	while (i < layout->getRelationship(this->relationshipName)->extents.size()*layout->getRelationship(this->relationshipName)->pagesPerExtent)
	{
		i=i+1024;
		cleanDBCache();
		startTimer();
		if(getDisk() == -1) break;
		for (int iteration = 0; iteration < numberOfIterations; iteration++)
		{
			for (unsigned long long int j = 0; j < i; j++)
			{
				writePage(getRandomPage());
			}
		}
		storeMeasurement();
	}

	writeTestLog();
}

} /* namespace HDDTest */
