/*
 * IndexScan.cpp
 *
 */

#include "IndexScan.h"

namespace DBTest
{

IndexScan::IndexScan()
{
	// TODO Auto-generated constructor stub
	std::cout << "indexScan" << std::endl;

}

IndexScan::~IndexScan()
{
	// TODO Auto-generated destructor stub
}

void IndexScan::testAlgorithm()
{
	std::cout << "TEST STARTED" << std::endl;
	unsigned long long int i = 1;
	HDDTest::Relationship *r = layout->getRelationship(this->relationshipName);
	std::cout << r->name << "##########################################";
	while (i < layout->getRelationship(this->relationshipName)->extents.size())
	{
		i=i+8;
		cleanDBCache();
		startTimer();
		for (int iteration = 0; iteration < numberOfIterations; iteration++)
		{
			for (unsigned long long int j = 0; j < i; j++)
			{
				readPage(getRandomPage());
			}
		}
		storeMeasurement();
		std::cout << i << ":" << getTime() / 1000000. / numberOfIterations << ":" << getMbPerSec() / numberOfIterations << std::endl;
	}
	writeTestLog();
}
}
