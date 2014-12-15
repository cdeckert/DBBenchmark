/*
 * Relationship.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: root
 */

#include "Relationship.h"

namespace HDDTest
{

Relationship::Relationship(std::string name, uint64_t size, unsigned int pagesPerExtent, unsigned int pageSizeInKB)
{
	this->name = name;
	this->extents.reserve(size);
	this->unallocatedExtents = size;
	this->pagesPerExtent = pagesPerExtent;
	this->pageSizeInKB = pageSizeInKB;

}

Relationship::~Relationship()
{
	// TODO Auto-generated destructor stub
}

void Relationship::addExtent(uint64_t start)
{
	struct Extent extent;
	extent.startKb = start;
	extent.number = extents.size();
	this->extents.push_back(extent);
	this->unallocatedExtents--;
}

void Relationship::setNextExtent(uint64_t nextExtent)
{
	this->nextExtent = nextExtent;
}

uint64_t Relationship::getNextExtent()
{
	if (isNextExtent())
	{
		uint64_t extentStart = this->extents.at(this->nextExtent).startKb;
		this->nextExtent++;
		return extentStart;
	}
	else
	{
		return 0;
	}

}

uint64_t Relationship::getPrevExtent()
{
	if (isNextExtent())
		{
			this->nextExtent--;
			uint64_t extentStart = this->extents.at(this->nextExtent).startKb;
			return extentStart;
		}
		else
		{
			return 0;
		}
}

bool Relationship::isNextExtent()
{
	return this->nextExtent < this->extents.size();
}

bool Relationship::isUnAllocatedExtent()
{
	return this->unallocatedExtents != 0;
}

int Relationship::getProbability(uint64_t totalUnallocatedExtents)
{
	int prob = this->unallocatedExtents * 100 / totalUnallocatedExtents ;
	return prob;
}

uint64_t Relationship::getRandomExtent()
{
	return this->extents[rand() % this->extents.size()].startKb;
}

uint64_t Relationship::getRandomPage()
{
	return this->extents[rand() % this->extents.size()].startKb + (rand() % this->pagesPerExtent) * this->pageSizeInKB;
}

} /* namespace HDDTest */
