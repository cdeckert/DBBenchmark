/**
 * @file	Layout.cpp
 * @Author	Christian Deckert (christian.deckert@zentrale2.com)
 * @date	October, 2014
 * @brief
 */

#include "Layout.h"

namespace HDDTest
{

Layout::Layout(LayoutSettings layoutSetting)
{
	this->init_rand();
	this->extentSizeInPages = layoutSetting.pagesPerExtent;
	this->pageSizeInKB = layoutSetting.pageSizeInKB;
	this->createRelationships(layoutSetting.relationships);
	this->diskStart = 0; // TODO
	if(layoutSetting.mode == "ordered")
	{
		this->distributionOrder = ORDERED;
	}
	else
	{
		this->distributionOrder = UNORDERED;
	}

}

Layout::~Layout()
{
	// TODO Auto-generated destructor stub
}


void Layout::createRelationships(std::vector<struct HDDTest::RelationshipConfig> relationshipConfigs)
{
	uint64_t totalRelSize = 0;
	for (struct HDDTest::RelationshipConfig relConf : relationshipConfigs)
	{
		totalRelSize += relConf.size;
	}


	for (struct HDDTest::RelationshipConfig relConf : relationshipConfigs)
	{
		this->relationships.push_back(new Relationship(relConf.name, relConf.size, this->extentSizeInPages, this->pageSizeInKB));
	}


	// distribution
	uint64_t relStart = this->diskStart;
	if(this->distributionOrder == ORDERED)
	{
		uint64_t i = 0;
		for (std::vector<HDDTest::Relationship *>::iterator r = this->relationships.begin(); r != this->relationships.end(); ++r)
		{
			while((*r)->isUnAllocatedExtent())
			{
				(*r)->addExtent(relStart + i * this->extentSizeInPages * this->pageSizeInKB);
				i++;
			}
		}
	}
	else // unordered Distribution
	{
		for (uint64_t i = 0; i != totalRelSize; i++)
		{
			int prob = 0;
			int aRandVal = rand() % 100 + 1;
			for (std::vector<HDDTest::Relationship *>::iterator r = this->relationships.begin(); r != this->relationships.end(); ++r)
			{
				prob += (*r)->getProbability(totalRelSize);
				if (prob >= aRandVal)
				{
					(*r)->addExtent(relStart + i * this->extentSizeInPages * this->pageSizeInKB);
					break;
				}
			}
		}
	}

}

HDDTest::Relationship *Layout::getRelationship(std::string name)
{
	for (std::vector<HDDTest::Relationship *>::iterator r = this->relationships.begin(); r != this->relationships.end(); ++r)
	{
		if ((*r)->name == name)
		{
			return *r;
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
