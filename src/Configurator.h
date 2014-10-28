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

using namespace rapidjson;
using namespace std;
namespace HDDTest
{


struct LayoutSettings
{
	string mode;
	unsigned int pageSizeInKB;
	unsigned int pagesPerExtent;
	vector<struct RelationshipConfig> relationships;
	vector<struct TestRun> testRuns;
};

struct Configuration
{
	vector<string> devices;

	struct LayoutSettings layout;
};

struct TestThread
{
	string relationship;
	string testName;
	int abc;
};

struct TestRun
{
	string name;
	struct TestThread mainThread;
	vector<struct TestThread> backgroundThreads;
};






struct RelationshipConfig
{
	unsigned int size;
	string name;
};

class Configurator
{
public:
	Configurator();
	virtual ~Configurator();
	void fetchConfigurations();
	struct Configuration configuration;


};

} /* namespace HDDTest */

#endif /* SRC_CONFIGURATOR_H_ */
