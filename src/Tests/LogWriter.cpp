/*
 * LogWriter.cpp
 *
 */

#include "LogWriter.h"

namespace DBTest
{

LogWriter::LogWriter()
{
	// TODO Auto-generated constructor stub


	this->setExtentSize(64);
}

LogWriter::~LogWriter()
{
	// TODO Auto-generated destructor stub
}

void LogWriter::testAlgorithm()
{
	std::cout << "Valid";
	openDisk("/dev/sdb");
	speedUpDisk();
	for (int i = 0; i < 10000; i++)
	{
		writeExtent(64000 * i);
	}
	std::cout << "DONE";

}

} /* namespace DBTest */
