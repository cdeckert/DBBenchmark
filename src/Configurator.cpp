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
		cout << itr->GetString() << endl;
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


		Value::ConstMemberIterator testRuns = run->FindMember("testRuns");
		for(Value::ConstValueIterator testRunIt = testRuns->value.Begin(); testRunIt != testRuns->value.Begin(); ++testRunIt)
		{
			struct TestRun testRun;
			testRun.mainThread.relationship = testRunIt->FindMember("mainThread")->value["relationship"].GetString();
			testRun.mainThread.testName = testRunIt->FindMember("mainThread")->value["testName"].GetString();





			configuration.layout.testRuns.push_back((testRun));
		}
	}






	//cout << "is Object: " << layoutSettings.IsObject() << endl;
	/*

	for (Value::ConstValueIterator itr = layoutSettings["relationshipAllocation"].Begin(); itr != layoutSettings["relationshipAllocation"].End(); ++itr)
	{

	}*/

	//configuration.layout = &layout;

	//Value &testRuns = run["testRuns"];







	fclose(pFile);


}




} /* namespace HDDTest */
