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
	Value& hostSettings = d[hostname];


	// read Configuration
	// read devices
	Value& devices = hostSettings["devices"];
	for(Value::ConstValueIterator itr = devices.Begin(); itr != devices.End(); ++itr)
	{
		configuration.devices.push_back(itr->GetString());
	}

	Value &testRuns = hostSettings["testRuns"];
	/*for(Value::ConstMemberIterator itr = testRuns.MemberBegin(); itr != testRuns.MemberEnd(); ++itr)
	{
		TestRun aTestRun;
		aTestRun.name = itr->value["name"].GetString();

		// main Test
		//aTestRun.mainThread;

		// background Threads
		cout << itr->value["backgroundThreads"].IsArray();
		Value& backgroundThreads = itr->value["backgroundThreads"];
		for(Value::ConstMemberIterator titr = backgroundThreads.MemberBegin(); titr != backgroundThreads.MemberEnd(); ++titr)
		{
			TestThread testThread;
			aTestRun.backgroundThreads.push_back(testThread);
		}
		configuration.testRuns.push_back(aTestRun);
	}*/





	fclose(pFile);


}




} /* namespace HDDTest */
