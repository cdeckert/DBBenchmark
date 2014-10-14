/*
 * ConfigReader.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#include "ConfigReader.h"


using namespace rapidjson;

namespace DBTest {

ConfigReader::ConfigReader() {
	std::string configFilePath;
	configFilePath = "config.json";

	readConfiguration(configFilePath);



}

void ConfigReader::readConfiguration(std::string configFilePath)
{
	/*
	FILE* fp = fopen(configFilePath.data(), "r");
	char readBuffer[256];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	std::cout << readBuffer;
	Document d;
	d.ParseStream(is);
	fclose(fp);

	*/
	//devicePath = d["devicePath"].GetString();
	//size_spread = std::ceil(d["size_spread_gb"].GetDouble() * 1024 * 1024);

	std::cout << devicePath;
}

ConfigReader::~ConfigReader() {
	// TODO Auto-generated destructor stub
}




} /* namespace DBTest */
