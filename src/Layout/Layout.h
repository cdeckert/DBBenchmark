/*
 * Layout.h
 *
 */

#include "Relationship.h"
#include "../Configurator.h"
#include <cmath>
#include <algorithm>

#ifndef SRC_LAYOUT_LAYOUT_H_
#define SRC_LAYOUT_LAYOUT_H_

namespace HDDTest
{
//enum modeDistributionOrder {ORDERED, UNORDERED};
//enum modeExtentDistribution {EQUALLY , ED_RANDOM};
class Layout
{
public:
	Layout();
	virtual ~Layout();

	void createRelationships(std::vector<struct HDDTest::RelationshipConfig>);

	unsigned long long int diskStart;
	int extentSizeInPages;
	int pageSizeInKB;

	HDDTest::Relationship* getRelationship(std::string);


private:
	std::vector<Relationship> relationships;
	void init_rand();


};

} /* namespace HDDTest */

#endif /* SRC_LAYOUT_LAYOUT_H_ */
