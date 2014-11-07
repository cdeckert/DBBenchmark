/*
 * Drive.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: root
 */

#include "Drive.h"
#include <map>
namespace DBTest {

Drive::Drive(std::string path) {
	// TODO Auto-generated constructor stub

}

Drive* Drive::get(std::string path)
{

	if(!Drive::drives.count(path))
	{
		//drives.insert(std::make_pair(path, new Drive(path)));
	}
	return Drive::drives.at(path);
	return NULL;
}

Drive::~Drive() {
	// TODO Auto-generated destructor stub
}

} /* namespace DBTest */
