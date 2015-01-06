#include "FullTableScan.h"

namespace HDDTest
{

FullTableScan::FullTableScan(std::string name, std::string layoutName, Layout * layout, Disk *disk, Relationship *relationship, double sleepTime) : ATest(name, layoutName, layout, disk, relationship, sleepTime) {}




void FullTableScan::executeTestAlgorithm()
{
	uint64_t processedData = 0;
	this->relationship->setNextExtent(0);
	if (isMain)
	{
		this->log->start();
	}
	/**do
	{
		this->disk->readExtent(this->relationship->getNextExtent());

		processedData += layout->getExtentSizeInKB();
		this->sleep();
		if (!this->runs) return;
	}
	while (this->relationship->isNextExtent());*/
	for(uint64_t i = 0; i < this->relationship->getNoOfExtents(); i++) {
		this->disk->readExtent(this->relationship->getExtent(i).startKb);

		processedData += layout->getExtentSizeInKB();

		this->sleep();

		if (!this->runs)
			return;
	}

	if (isMain)
	{
		this->log->stop(processedData);
	}
}

FullTableScan::~FullTableScan()
{
	// TODO Auto-generated destructor stub
}

} /* namespace HDDTest */
