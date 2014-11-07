/*
 * Disk.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: root
 */

#include "Disk.h"

namespace DBTest {

std::unordered_map<std::string, Disk*> Disk::disks;

Disk* Disk::get(std::string path)
{
	if(disks.count(path) == 0)
	{
		disks.insert(std::make_pair(path, new Disk(path)));
	}
	return disks.at(path);
}


Disk::Disk(std::string path)
{
	this->path = path;
	this->fd = open64(path.data(), O_RDWR | O_SYNC);
	this->extentSize = 64*1024; // standard size
	this->pageSize = 8*1024; // page size
}

void Disk::del()
{
	close(this->fd);
	disks.erase(this->path);
}

bool Disk::isValid()
{
	return this->fd != -1;
}

Disk::~Disk() {
	// TODO Auto-generated destructor stub
}

} /* namespace DBTest */
