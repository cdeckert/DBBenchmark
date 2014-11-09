/*
 * Layout.h
 *
 */

#include "Relationship.h"
#include <cmath>
#include <algorithm>

#ifndef SRC_LAYOUT_LAYOUT_H_
#define SRC_LAYOUT_LAYOUT_H_

namespace HDDTest
{
//enum modeDistributionOrder {ORDERED, UNORDERED};
//enum modeExtentDistribution {EQUALLY , ED_RANDOM};

struct RelationshipConfig
{
	unsigned int size;
	std::string name;
};


struct LayoutSettings
{
	std::string mode;
	uint64_t pageSizeInKB;
	uint64_t pagesPerExtent;
	std::vector<struct RelationshipConfig> relationships;
};

class Layout
{
public:
	Layout(struct LayoutSettings);
	virtual ~Layout();

	void createRelationships(std::vector<struct RelationshipConfig>);

	uint64_t diskStart;


	HDDTest::Relationship* getRelationship(std::string);


private:
	std::vector<Relationship*> relationships;
	int extentSizeInPages;
	int pageSizeInKB;
	void init_rand();


};

} /* namespace HDDTest */

#endif /* SRC_LAYOUT_LAYOUT_H_ */
