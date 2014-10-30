/*
 * Configurator.cpp
 *
 */

#include "Configurator.h"



using namespace rapidjson;
namespace HDDTest
{

Configurator::Configurator()
{
	// TODO Auto-generated constructor stub

}

Configurator::~Configurator()
{
	// TODO Auto-generated destructor stub
}



void Configurator::fetchConfigurations()
{
	// config file
	FILE *pFile = fopen ("config.json" , "r");
	FileStream fs(pFile);
	Document d;
	d.ParseStream(fs);

	// host name
	char hostname[1024];
	gethostname(hostname, 1024);

	Value &hostSettings = d[hostname];

	// read Configuration
	// read devices
	Value &devices = hostSettings["devices"];
	for (Value::ConstValueIterator itr = devices.Begin(); itr != devices.End(); ++itr)
	{
		configuration.devices.push_back(itr->GetString());
	}


	Value &runs = hostSettings["runs"];
	for(Value::ConstValueIterator run = runs.Begin(); run != runs.End(); ++run)
	{
		Value::ConstMemberIterator layoutSettings = run->FindMember("layoutSettings");

		configuration.layout.mode = layoutSettings->value["mode"].GetString();
		configuration.layout.pageSizeInKB = layoutSettings->value["pageSizeInKB"].GetUint();
		configuration.layout.pagesPerExtent = layoutSettings->value["pagesPerExtent"].GetUint();

		for(Value::ConstMemberIterator relationshipSetting = layoutSettings->value["relationshipAllocation"].MemberBegin(); relationshipSetting != layoutSettings->value["relationshipAllocation"].MemberEnd(); ++relationshipSetting)
		{
			struct RelationshipConfig relConf;
			relConf.name = relationshipSetting->name.GetString();
			relConf.size = relationshipSetting->value.GetUint();
			configuration.layout.relationships.push_back(relConf);


			// test methods
			//configuration.layout.testRuns.mainThread.
		}


		for(Value::ConstValueIterator testRunIt = run->FindMember("testRuns")->value.Begin(); testRunIt != run->FindMember("testRuns")->value.End(); ++testRunIt)
		{
			struct TestRun testRun;
			testRun.mainThread.relationship = testRunIt->FindMember("mainThread")->value["relationship"].GetString();
			testRun.mainThread.testName = testRunIt->FindMember("mainThread")->value["testName"].GetString();


			for(Value::ConstValueIterator backgroundJobIt = testRunIt->FindMember("backgroundThreads")->value.Begin(); backgroundJobIt != testRunIt->FindMember("backgroundThreads")->value.End(); ++backgroundJobIt)
			{
				struct TestThread bgJob;
				bgJob.relationship = backgroundJobIt->FindMember("relationship")->value.GetString();
				bgJob.testName = backgroundJobIt->FindMember("testName")->value.GetString();
				testRun.backgroundThreads.push_back(bgJob);
			}


			configuration.layout.testRuns.push_back((testRun));
		}
	}
	fclose(pFile);


}




} /* namespace HDDTest */
