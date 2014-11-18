/**
 * Disk manager
 */

#include "Disk.h"

namespace HDDTest
{

// init disks
std::unordered_map<std::string, Disk *> Disk::disks;

/**
 * @brief returns disk
 * @details returns a disk pointer
 *
 * @param path disk path
 * @return pointer to disk instance
 */
Disk *Disk::get(std::string path)
{
	if (disks.count(path) == 0)
	{
		disks.insert(std::make_pair(path, new Disk(path)));
	}
	return disks.at(path);
}


/**
 * @brief Disk constructor
 * @details The disk constructor initalizes a disk based on a given path
 *
 * @param path Disk-path
 */
Disk::Disk(std::string path)
{
	this->open(path);
	this->setExtentSize(64); // standard size in kb
	this->setPageSize(8); // page size in kb
	this->startup();
}

/**
 * @brief open a disk
 * @details Opens a disk and sets a member variable called path
 *
 * @param path Disk-path
 */
void Disk::open(std::string path)
{
	this->path = path;
	this->fd = open64(this->path.data(), O_RDWR |  O_LARGEFILE | O_SYNC); // O_DIRECT
	if(fd == -1) perror("Disk.cpp: OPEN");
}


/**
 * @brief speeds up a disk
 * @details speeds up a disk and read the 1 GB of data
 */
void Disk::startup()
{
	if (this->isValid())
	{
		char *buffer = new char[128 * 1024 * 1024];;
		lseek64(this->fd, -128 * 1024 * 1024, SEEK_END);
		read(this->fd, buffer, 128 * 1024 * 1024);
		delete buffer;
	}
}

/**
 * @brief extent-size-setter
 * @details sets the extent size in kb
 *
 * @param size Size of a extent in kb
 */
void Disk::setExtentSize(int size)
{
	this->extentSize = size;
	this->extentBuffer = new char[extentSize * 1024];
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param size [description]
 */
void Disk::setPageSize(int size)
{
	this->pageSize = size;
	this->pageBuffer = new char[pageSize * 1024];
}


void Disk::readExtent(uint64_t start)
{
	lseek64(this->fd, start * 1024, SEEK_SET);
	read(this->fd, this->extentBuffer, this->extentSize * 1024);
}

void Disk::readPage(uint64_t start)
{

	lseek64(this->fd, start * 1024, SEEK_SET);
	read(this->fd, this->pageBuffer, this->pageSize * 1024);
	//perror("read");
}

void Disk::writeExtent(uint64_t start)
{
	lseek64(this->fd, start * 1024, SEEK_SET);
	write(this->fd, this->extentBuffer, this->extentSize * 1024);
}

void Disk::writePage(uint64_t start)
{
	lseek64(this->fd, start * 1024, SEEK_SET);
	write(this->fd, this->pageBuffer, this->pageSize * 1024);
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



std::string Disk::getName()
{
	std::string name = this->path;
	return name.replace(name.find("/dev/"), 5, "");
}
} /* namespace DBTest */
