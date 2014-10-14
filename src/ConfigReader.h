/*
 * ConfigReader.h
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <cmath>

using namespace rapidjson;

namespace DBTest {

class ConfigReader {
public:
	ConfigReader();
	virtual ~ConfigReader();

	struct configuration
	{
		int extentSize;
		int pageSize;
	};

private:
	void readConfiguration(std::string);
	std::string devicePath;
	unsigned long long int size_spread;
};

} /* namespace DBTest */

#endif /* CONFIGREADER_H_ */
