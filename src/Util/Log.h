/*
 * Log.h
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#ifndef SRC_UTIL_LOG_H_
#define SRC_UTIL_LOG_H_
#include <inttypes.h>

namespace DBUtil
{

class Log
{
public:
	Log();
	virtual ~Log();
	void start();
	void stop(uint64_t);
};

} /* namespace HDDTest */

#endif /* SRC_UTIL_LOG_H_ */
