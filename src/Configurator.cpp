/*
 * Configurator.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: root
 */

#include "Configurator.h"
#include <rapidjson/document.h>
#include <rapidjson/filestream.h>
#include <iostream>
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
	FILE * pFile = fopen ("config.json" , "r");
	FileStream fs(pFile);
	Document d;
	d.ParseStream(fs);


	std::cout << d["auriga"].IsObject();



	fclose(pFile);


}


} /* namespace HDDTest */
