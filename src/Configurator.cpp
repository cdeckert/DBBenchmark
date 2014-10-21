/*
 * Configurator.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: root
 */

#include "Configurator.h"



using namespace rapidjson;
namespace HDDTest {

Configurator::Configurator() {
	// TODO Auto-generated constructor stub

}

Configurator::~Configurator() {
	// TODO Auto-generated destructor stub
}



void Configurator::fetchConfigurations()
{
	// config file
	FILE * pFile = fopen ("config.json" , "r");
	FileStream fs(pFile);
	Document d;
	d.ParseStream(fs);

	// host name
	char hostname[1024];
	gethostname(hostname, 1024);

	std::cout << hostname;
	Value &hostSettings = d[hostname];






	fclose(pFile);


}


} /* namespace HDDTest */
