/*
 * Layout.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: root
 */

#include "Layout.h"

namespace HDDTest {

Layout::Layout() {
	init_rand();

}

Layout::~Layout() {
	// TODO Auto-generated destructor stub
}


void Layout::createRelationships(std::vector<struct HDDTest::RelationshipConfig> relationshipConfigs)
{
	unsigned long long int totalRelSize = 0;
	for(struct HDDTest::RelationshipConfig relConf : relationshipConfigs)
	{
		totalRelSize+= relConf.size;
	}

	std::cout <<"totalRelSize" <<  totalRelSize << std::endl;

	for(struct HDDTest::RelationshipConfig relConf : relationshipConfigs)
	{
		this->relationships.push_back(HDDTest::Relationship(relConf.name, relConf.size, this->extentSizeInPages, this->pageSizeInKB));
	}


	// distribution
	unsigned long long int relStart = this->diskStart;

	for(unsigned long long int i = 0;i != totalRelSize; i++)
	{
		int prob = 0;
		int aRandVal = rand()%100+1;
		for(std::vector<HDDTest::Relationship>::iterator r = this->relationships.begin(); r != this->relationships.end(); ++r)
		{
			prob += r->getProbability(totalRelSize);
			if(prob >= aRandVal)
			{
				std::cout << "relation:" << r->name << i << std::endl;
				r->addExtent(relStart + i * this->extentSizeInPages * this->pageSizeInKB * 1024);
				break;
			}

		}
	}
}

HDDTest::Relationship* Layout::getRelationship(std::string name)
{
	for(std::vector<HDDTest::Relationship>::iterator r = this->relationships.begin(); r != this->relationships.end(); ++r)
	{
		if(r->name == name)
		{
			return &*r;
		}
	}
	return NULL;
}

void Layout::init_rand()
{
	time_t t;

	time(&t);
	srand((unsigned int)t);
}



} /* namespace HDDTest */
