/*
 * Layout.h
 *
 */

#include "Relationship.h"
#include "../Configurator.h"

#ifndef SRC_LAYOUT_LAYOUT_H_
#define SRC_LAYOUT_LAYOUT_H_

namespace HDDTest
{
enum modeDistributionOrder {ORDERED, UNORDERED};
enum modeExtentDistribution {EQUALLY , ED_RANDOM};
class Layout
{
public:
	Layout();
	virtual ~Layout();

	void createRelationships(std::vector<struct HDDTest::RelationshipConfig>);

	unsigned long long int getDiskStart() const {
		return diskStart;
	}

	void setDiskStart(unsigned long long int diskStart) {
		this->diskStart = diskStart;
	}

	int getExtentSizeInPages() const {
		return extentSizeInPages;
	}

	void setExtentSizeInPages(int extentSizeInPages) {
		this->extentSizeInPages = extentSizeInPages;
	}

	int getPageSizeInKb() const {
		return pageSizeInKB;
	}

	void setPageSizeInKb(int pageSizeInKb) {
		pageSizeInKB = pageSizeInKb;
	}

private:
	std::vector<Relationship> relationships;
	unsigned long long int diskStart;
	int extentSizeInPages;
	int pageSizeInKB;

};

} /* namespace HDDTest */

#endif /* SRC_LAYOUT_LAYOUT_H_ */
