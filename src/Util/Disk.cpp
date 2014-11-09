/*
 * Disk.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: root
 */

#include "Disk.h"

namespace HDDTest
{

// init disks
std::unordered_map<std::string, Disk*> Disk::disks;


Disk* Disk::get(std::string path)
{
	if(disks.count(path) == 0)
	{
		disks.insert(std::make_pair(path, new Disk(path)));
	}
	return disks.at(path);
}


// private
Disk::Disk(std::string path)
{
	this->open(path);
	this->setExtentSize(64); // standard size in kb
	this->setPageSize(8); // page size in kb
	this->startup();
}

void Disk::open(std::string path)
{
	std::cout << "PATH: "<< path;
	this->path = path;

	this->fd = open64(this->path.data(), O_RDWR | O_SYNC);
}


void Disk::startup()
{
	if(this->isValid())
	{
		char *buffer = new char[128 * 1024 * 1024];;
		lseek64(this->fd, -128 * 1024 * 1024, SEEK_END);
		read(this->fd, buffer, 128 * 1024 * 1024);
	}
}

void Disk::setExtentSize(int size)
{
	this->extentSize = size;
	this->extentBuffer = new char[extentSize * 1024];
}

void Disk::setPageSize(int size)
{
	this->pageSize = size;
	this->pageBuffer = new char[pageSize * 1024];
}


void Disk::readExtent(uint64_t start)
{
	lseek64(this->fd, start*1024, SEEK_SET);
	read(this->fd, this->extentBuffer, this->extentSize*1024);
}

void Disk::readPage(uint64_t start)
{

	lseek64(this->fd, start*1024, SEEK_SET);
	read(this->fd, this->pageBuffer, this->pageSize*1024);
}

void Disk::writeExtent(uint64_t start)
{
	lseek64(this->fd, start*1024, SEEK_SET);
	write(this->fd, this->extentBuffer, this->extentSize*1024);
}

void Disk::writePage(uint64_t start)
{
	lseek64(this->fd, start*1024, SEEK_SET);
	write(this->fd, this->pageBuffer, this->pageSize*1024);
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

Disk::~Disk()
{
}

} /* namespace DBTest */
