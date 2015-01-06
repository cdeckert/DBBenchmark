/*
 * Relationship.h
 *
 *  Created on: Oct 28, 2014
 *      Author: root
 */

#ifndef SRC_LAYOUT_RELATIONSHIP_H_
#define SRC_LAYOUT_RELATIONSHIP_H_
#include <iostream>
#include <vector>
namespace HDDTest
{

struct Extent
{
	uint64_t number;
	uint64_t startKb;
};

class Relationship
{
public:
	Relationship(std::string, uint64_t, unsigned int, unsigned int);
	virtual ~Relationship();
	void addExtent(uint64_t);

	int getProbability(uint64_t);

	void setUnallocatedExtents(uint64_t unallocatedExtents)
	{
		this->unallocatedExtents = unallocatedExtents;
	}



	uint64_t getRandomExtent();
	uint64_t getRandomPage();

	uint64_t getNextExtent();
	uint64_t getPrevExtent();
	uint64_t getNextPage();

	uint64_t getNoOfExtents();

	struct Extent getExtent(uint64_t);

	bool isNextExtent();
	bool isUnAllocatedExtent();
	std::string name;

	unsigned int pagesPerExtent;
	unsigned int pageSizeInKB;

	void setNextExtent(uint64_t);

private:
	uint64_t unallocatedExtents;
	uint64_t nextExtent = 0;
	uint64_t currentExtent = 0;
	unsigned int pageNumber = 0;
	std::vector<struct Extent> extents;

};

} /* namespace HDDTest */

#endif /* SRC_LAYOUT_RELATIONSHIP_H_ */
