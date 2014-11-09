/*
 * Progressbar.h
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#ifndef SRC_UTIL_PROGRESSBAR_H_
#define SRC_UTIL_PROGRESSBAR_H_
#include <stdint.h>
#include <iostream>
namespace HDDTest
{

class Progressbar
{
public:
	Progressbar(std::string, uint64_t);
	void add(uint64_t);
	uint64_t total;
	uint64_t current;
	int barWidth;
	std::string name;
	virtual ~Progressbar();
private:
	int old;
};

} /* namespace HDDTest */

#endif /* SRC_UTIL_PROGRESSBAR_H_ */
