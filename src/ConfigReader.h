/*
 * ConfigReader.h
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_

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
};

} /* namespace DBTest */

#endif /* CONFIGREADER_H_ */
