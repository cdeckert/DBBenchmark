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
	unsigned long long int number;
	unsigned long long int startKb;
};

class Relationship
{
public:
	Relationship(std::string, unsigned long long int, unsigned int, unsigned int);
	virtual ~Relationship();
	void addExtent(unsigned long long int);

	int getProbability(unsigned long long int);

	void setUnallocatedExtents(unsigned long long int unallocatedExtents) {
		this->unallocatedExtents = unallocatedExtents;
	}



	unsigned long long int getRandomExtent();
	unsigned long long int getRandomPage();

	unsigned long long int getNextExtent();
	unsigned long long int getNextPage();
	bool isNextExtent();
	std::vector<struct Extent> extents;
	std::string name;

	unsigned int pagesPerExtent;
	unsigned int pageSizeInKB;

private:
	unsigned long long int unallocatedExtents;
	unsigned long long int nextExtent = 0;

};

} /* namespace HDDTest */

#endif /* SRC_LAYOUT_RELATIONSHIP_H_ */
