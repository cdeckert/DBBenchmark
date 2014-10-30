/*
 * NoTest.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: root
 */

#include "NoTest.h"

namespace DBTest {

NoTest::NoTest() {
	// TODO Auto-generated constructor stub

}

NoTest::~NoTest() {
	// TODO Auto-generated destructor stub
}

void NoTest::testAlgorithm()
{
	unsigned int iterator = 1;
	for(int i = 0; i < 20000; i++)
	{
		iterator ++;
		iterator = iterator *2;
		iterator = iterator / 2;
	}
}

} /* namespace HDDTest */
