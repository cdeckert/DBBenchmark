/*
 * TestScenario.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#include "TestScenario.h"
#include "../Util/Progressbar.h"


namespace HDDTest {

TestScenario::TestScenario(std::vector<std::string> *diskPaths, std::unordered_map<std::string, Layout*> *layouts, TestSettings mainThreadSettings, std::vector<TestSettings> backgroundThreadsSettings)
{
	this->diskPaths = diskPaths;
	this->layouts = layouts;
	this->mainThreadSettings = mainThreadSettings;
	this->backgroundThreadsSettings = backgroundThreadsSettings;
}

TestScenario::~TestScenario() {
	// TODO Auto-generated destructor stub
}


void TestScenario::run()
{
	std::cout << "Start Test Scenario" << std::endl;
	Progressbar *scenarioProgress = new Progressbar("Szenario",this->getNumberOfTests());
	for(std::vector<std::string>::iterator diskItr = diskPaths->begin(); diskItr != diskPaths->end(); ++diskItr)
	{
		Disk *disk = Disk::get(*diskItr);

		ATest *mainThread;

		std::cout << "first" << layouts->begin()->first;
		Layout *layout = layouts->at("ordered GB");

		std::cout << layout->diskStart;

		mainThread = new IndexScan(mainThreadSettings.name, disk, layout->getRelationship(mainThreadSettings.relationship));


		if(mainThreadSettings.name == "IndexScan")
		{

		}

		scenarioProgress->add(1);
		mainThread->start();


		scenarioProgress->add(1);
	}
}




int TestScenario::getNumberOfTests()
{
	return this->layouts->size() * this->diskPaths->size();
}

} /* namespace HDDTest */
