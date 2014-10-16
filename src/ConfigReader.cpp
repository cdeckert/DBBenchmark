/*
 * ConfigReader.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: root
 */

#include "ConfigReader.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace rapidjson;

namespace DBTest {

ConfigReader::ConfigReader() {
	std::string configFilePath;
	configFilePath = "config.json";

	readConfiguration(configFilePath);



}

void ConfigReader::readConfiguration(std::string configFilePath)
{

	std::ifstream configFile;
	configFile.open(configFilePath.c_str());
	std::stringstream ss;

	ss << configFile.rdbuf();


	//std::cout << configFile;
	Document d;
	d.Parse(ss.str().c_str());

	configFile.close();




	//devicePath = d["devicePath"].GetString();
	//size_spread = std::ceil(d["size_spread_gb"].GetDouble() * 1024 * 1024);

	//std::cout << devicePath;
}

ConfigReader::~ConfigReader() {
	// TODO Auto-generated destructor stub
}




} /* namespace DBTest */
