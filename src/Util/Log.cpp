/*
 * Log.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "Log.h"

namespace DBUtil
{

Log::Log()
{
	this->measurements = new std::vector<struct measurement>();

}

Log::~Log()
{
	// TODO Auto-generated destructor stub
}

void Log::start()
{
	clock_gettime(CLOCK_REALTIME, &startTime);
}

void Log::stop(uint64_t size)
{
	measurement m;
	m.size = size;
	timespec endTime;
	clock_gettime(CLOCK_REALTIME, &endTime);
	m.duration = (endTime.tv_sec - startTime.tv_sec) * 1000000000 + (endTime.tv_nsec - startTime.tv_nsec);
	measurements->push_back(m);
}

} /* namespace HDDTest */
