/*
 * Configurator.h
 *
 */

#ifndef SRC_CONFIGURATOR_H_
#define SRC_CONFIGURATOR_H_

#include <rapidjson/document.h>
#include <rapidjson/filestream.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <unordered_map>
#include "../Tests/TestScenario.h"
#include "Disk.h"
#include "../Layout/Layout.h"

using namespace rapidjson;
namespace HDDTest {


class Configurator
{
public:
	Configurator();
	virtual ~Configurator();
	std::vector<TestScenario*>* getTestScenarios();
};

} /* namespace HDDTest */

#endif /* SRC_CONFIGURATOR_H_ */
