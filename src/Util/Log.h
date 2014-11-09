/*
 * Log.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_UTIL_LOG_H_
#define SRC_UTIL_LOG_H_
#include <inttypes.h>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>

namespace DBUtil
{

struct measurement
{
	uint64_t duration;
	uint64_t size;
};

class Log
{
public:
	Log();
	virtual ~Log();
	void start();
	void stop(uint64_t);
	void write(std::string);

private:
	timespec startTime;
	std::vector<struct measurement> *measurements;
};

} /* namespace HDDTest */

#endif /* SRC_UTIL_LOG_H_ */
