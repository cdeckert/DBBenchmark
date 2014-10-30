/*
 * Relationship.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: root
 */

#include "Relationship.h"

namespace HDDTest {

Relationship::Relationship(std::string name, unsigned long long int size, unsigned int pagesPerExtent, unsigned int pageSizeInKB)
{
	this->name = name;
	this->extents.reserve(size);
	this->unallocatedExtents = size;
	this->pagesPerExtent = pagesPerExtent;
	this->pageSizeInKB = pageSizeInKB;

}

Relationship::~Relationship() {
	// TODO Auto-generated destructor stub
}

void Relationship::addExtent(unsigned long long int start)
{
	struct Extent extent;
	extent.startKb = start;
	extent.number = extents.size();
	this->extents.push_back(extent);
	this->unallocatedExtents--;
}

unsigned long long int Relationship::getNextExtent()
{
	if(isNextExtent())
	{
	unsigned long long int extentStart = this->extents.at(this->nextExtent).startKb;
	this->nextExtent++;
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

int Relationship::getProbability(unsigned long long int totalUnallocatedExtents)
{
	int prob = this->unallocatedExtents*100 / totalUnallocatedExtents ;
	return prob;
}

unsigned long long int Relationship::getRandomExtent()
{
	return this->extents[rand() % this->extents.size()].startKb;
}

unsigned long long int Relationship::getRandomPage()
{
	return this->extents[rand() % this->extents.size()].startKb + (rand() % this->pagesPerExtent) * this->pageSizeInKB;
}

} /* namespace HDDTest */
