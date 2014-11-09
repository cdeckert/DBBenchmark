/*
 * Log.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: root
 */

#include "Log.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;


namespace DBUtil
{

Log::Log()
{
	this->measurements = new std::vector<struct measurement>();

}

Log::~Log()
{
	delete measurements;
}

void Log::start()
{
	clock_gettime(CLOCK_REALTIME, &startTime);
}

void Log::stop(uint64_t size)
{
	measurement m;
	m.size = size;
	timespec endTime;
	clock_gettime(CLOCK_REALTIME, &endTime);
	m.duration = (endTime.tv_sec - startTime.tv_sec) * 1000000000 + (endTime.tv_nsec - startTime.tv_nsec);
	measurements->push_back(m);
}

void Log::write(std::string name)
{
	StringBuffer s;
	Writer<StringBuffer> writer(s);
	writer.StartObject();
	writer.String("name");
	writer.String(name.data());
	writer.String("measurements");
	writer.StartArray();

	for(std::vector<struct measurement>::iterator itr = measurements->begin(); itr != measurements->end(); ++itr)
	{
		writer.StartObject();
		writer.String("duration");
		writer.Uint64(itr->duration);

		writer.String("size");
		writer.Uint64(itr->size);
		writer.EndObject();
	}
	writer.EndArray();
	writer.EndObject();


	std::ofstream json;
	json.open(name+".json");
	json << s.GetString();
	json.close();
}

} /* namespace HDDTest */
