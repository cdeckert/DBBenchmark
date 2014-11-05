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
#include <string>

/*using namespace rapidjson;
using namespace std;*/

namespace HDDTest
{


struct LayoutSettings
{
	std::string mode;
	unsigned int pageSizeInKB;
	unsigned int pagesPerExtent;
	std::vector<struct RelationshipConfig> relationships;
	std::vector<struct TestRun> testRuns;
};

struct Configuration
{
	std::vector<std::string> devices;

	struct LayoutSettings layout;
};

struct TestThread
{
	std::string relationship;
	std::string testName;
	int abc;
};

struct TestRun
{
	std::string name;
	struct TestThread mainThread;
	std::vector<struct TestThread> backgroundThreads;
};


struct RelationshipConfig
{
	unsigned int size;
	std::string name;
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
