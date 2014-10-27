/*
 * Configurator.h
 *
 *  Created on: Oct 21, 2014
 *      Author: root
 */

#ifndef SRC_CONFIGURATOR_H_
#define SRC_CONFIGURATOR_H_

#include <rapidjson/document.h>
#include <rapidjson/filestream.h>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace rapidjson;
using namespace std;
namespace HDDTest {

struct Configuration
{
	vector<string> devices;
	vector<struct TestRun> testRuns;
};

struct TestRun
{
	string name;
	//struct TestThread mainThread;
	vector<struct TestThread> backgroundThreads;
};


struct TestThread
{

};

class Configurator {
public:
	Configurator();
	virtual ~Configurator();
	void fetchConfigurations();
	struct Configuration configuration;


};

} /* namespace HDDTest */

#endif /* SRC_CONFIGURATOR_H_ */
