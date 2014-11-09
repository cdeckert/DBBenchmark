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








std::vector<TestScenario*>* HDDTest::Configurator::getTestScenarios()
{
	FILE *pFile = fopen ("config.json" , "r");
	FileStream fs(pFile);
	Document d;
	d.ParseStream(fs);

	// host name
	char hostname[1024];
	gethostname(hostname, 1024);

	Value &hostSettings = d[hostname];

	// disks
	std::vector<std::string*> *diskPaths = new std::vector<std::string*>();
	Value &disks = hostSettings["disks"];
	for (Value::ConstValueIterator itr = disks.Begin(); itr != disks.End(); ++itr)
	{
		std::string diskPath = itr->GetString();
		diskPaths->push_back(&diskPath);
	}


	// layout generation
	Value &layoutSettings = d["layouts"];
	std::unordered_map<std::string, Layout*>*layouts = new std::unordered_map<std::string, Layout*>();
	for(Value::ConstMemberIterator itr = layoutSettings.MemberBegin(); itr != layoutSettings.MemberEnd(); ++itr)
	{
		std::string name = itr->name.GetString();

		struct LayoutSettings layoutSetting;
		layoutSetting.mode = itr->value["mode"].GetString();
		layoutSetting.pageSizeInKB = itr->value["pageSizeInKB"].GetUint();
		layoutSetting.pagesPerExtent = itr->value["pagesPerExtent"].GetUint();

		for(Value::ConstMemberIterator relationshipSetting = itr->value["relationshipAllocation"].MemberBegin(); relationshipSetting != itr->value["relationshipAllocation"].MemberEnd(); ++relationshipSetting)
		{
			struct RelationshipConfig relConf;
			relConf.name = relationshipSetting->name.GetString();
			relConf.size = relationshipSetting->value.GetUint();
			layoutSetting.relationships.push_back(relConf);
		}


		layouts->insert(std::make_pair(name, new Layout(layoutSetting)));
	}

	std::vector<TestScenario*> *scenarios = new std::vector<TestScenario*>();
	// test scenarios
	TestScenario *testScenario = new TestScenario(diskPaths, layouts);



	scenarios->push_back(testScenario);






	fclose(pFile);
	return scenarios;
}
} /* namespace HDDTest */
