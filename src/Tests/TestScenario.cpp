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
		std::cout << "Start Test\n";
		Disk *disk = Disk::get(*diskItr);

		std::cout << "DISK::::" << disk->getName() << std::endl;
		Layout *layout = layouts->at("ordered GB");


		std::vector<ATest*> background;
		for(std::vector<struct TestSettings>::iterator itr = this->backgroundThreadsSettings.begin(); itr != this->backgroundThreadsSettings.end(); ++itr)
		{
			std::cout << "start background thread: " << itr->name << ", " << disk->getPath() << "\n";
			ATest *backgroundThread = new IndexScan(itr->name, disk, layout->getRelationship(itr->relationship));
			backgroundThread->isMain = false;
			backgroundThread->startBackground();
			std::cout << "\n";
		}




		std::cout << "start main\n";
		ATest *mainThread;




		mainThread = new IndexScan(mainThreadSettings.name, disk, layout->getRelationship(mainThreadSettings.relationship));


		if (mainThreadSettings.name == "IndexScan")
		{
			mainThread = new IndexScan(mainThreadSettings.name, disk, layout->getRelationship(mainThreadSettings.relationship));
		}
		else if(mainThreadSettings.name == "IndexWrite")
		{
			mainThread = new IndexWrite(mainThreadSettings.name, disk, layout->getRelationship(mainThreadSettings.relationship));
		}

		mainThread->isMain = true;

		scenarioProgress->add(1);
		mainThread->start();


		char hostname[1024];
		gethostname(hostname, 1024);
		std::string host(hostname);


		mainThread->log->write(host +"-"+disk->getName()+"-"+name);
		delete mainThread;


		scenarioProgress->add(1);
	}
}




int TestScenario::getNumberOfTests()
{
	return this->layouts->size() * this->diskPaths->size();
}

ATest* TestScenario::initTest(struct TestSettings testSettings) {
	ATest *test;
	return test;
}

} /* namespace HDDTest */
