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
		std::cout << "\nRelationship.cpp: getNextExtent() - nextExtent: " << this->nextExtent<< "\n";
		uint64_t extentStart = this->extents.at(this->nextExtent).startKb;
		this->nextExtent++;
		return extentStart;
	}
	else
	{
		return 0;
	}

}

uint64_t Relationship::getNextPage()
{
	uint64_t nextPage;
	if(this->pageNumber == 0)
	{
		this->currentExtent = this->getNextExtent();
		nextPage = this->currentExtent;
	}

	nextPage = currentExtent + this->pageNumber * this->pageSizeInKB;
	pageNumber++;
	if(pageNumber == this->pagesPerExtent)
	{
		pageNumber = 0;
	}

	return nextPage;
}


uint64_t Relationship::getPrevExtent()
{
	if (isNextExtent())
		{
			this->nextExtent--;
			uint64_t extentStart = 0;
			if(isNextExtent()) { // in case we get below 0 we just take the current extent
				std::cout << "\nRelationship.cpp: getPrivExtent()-1 - privExtent: " << this->nextExtent<< "\n";
				extentStart = this->extents.at(this->nextExtent).startKb;
			} else {
				this->nextExtent++;
				std::cout << "\nRelationship.cpp: getPrivExtent()-2 - privExtent: " << this->nextExtent<< "\n";
				extentStart = this->extents.at(this->nextExtent).startKb;
			}
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
	uint64_t randExtent = rand() % this->extents.size();
	uint64_t randPage = (rand() % this->pagesPerExtent) * this->pageSizeInKB;
	std::cout << "\nRelationship.cpp: getRandomPage() - extent " << randExtent << " | page: " << randPage << "\n";
	return this->extents[randExtent].startKb + randPage;
}

} /* namespace HDDTest */
