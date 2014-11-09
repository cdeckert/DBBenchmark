/*
 * TestScenario.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#include "TestScenario.h"
#include "../Util/Progressbar.h"


namespace HDDTest
{

TestScenario::TestScenario(std::string name, std::vector<std::string> *diskPaths, std::unordered_map<std::string, Layout *> *layouts, TestSettings mainThreadSettings, std::vector<TestSettings> backgroundThreadsSettings)
{
	this->diskPaths = diskPaths;
	this->layouts = layouts;
	this->name = name;
	this->mainThreadSettings = mainThreadSettings;
	this->backgroundThreadsSettings = backgroundThreadsSettings;
}

TestScenario::~TestScenario()
{

}


void TestScenario::run()
{
	std::cout << "Start Test Scenario" << std::endl;
	Progressbar *scenarioProgress = new Progressbar("Szenario", this->getNumberOfTests());
	for (std::vector<std::string>::iterator diskItr = diskPaths->begin(); diskItr != diskPaths->end(); ++diskItr)
	{
		Disk *disk = Disk::get(*diskItr);
		Layout *layout = layouts->at("ordered GB");


		std::vector<ATest*> background;
		for(std::vector<struct TestSettings>::iterator itr = this->backgroundThreadsSettings.begin(); itr != this->backgroundThreadsSettings.end(); ++itr)
		{
			ATest *backgroundThread = new IndexScan(itr->name, disk, layout->getRelationship(itr->relationship));
			backgroundThread->isMain = false;
			backgroundThread->startBackground();
		}





		ATest *mainThread;




		mainThread = new IndexScan(mainThreadSettings.name, disk, layout->getRelationship(mainThreadSettings.relationship));
		mainThread->isMain = true;

		if (mainThreadSettings.name == "IndexScan")
		{

		}

		scenarioProgress->add(1);
		mainThread->start();

		mainThread->log->write(name);
		delete mainThread;


		scenarioProgress->add(1);
	}
}




int TestScenario::getNumberOfTests()
{
	return this->layouts->size() * this->diskPaths->size();
}

ATest* TestScenario::initTest(struct TestSettings testSettings) {
}

} /* namespace HDDTest */
