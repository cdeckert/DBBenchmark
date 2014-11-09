/*
 * Progressbar.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: root
 */

#include "Progressbar.h"


namespace HDDTest {

Progressbar::Progressbar(std::string name, uint64_t total) {
	this->total = total;
	this->current = 0;
	this->barWidth = 70;
	this->name = name;

}

void Progressbar::add(uint64_t addition)
{
	this->current = this->current + addition;
	int pos = 1. * this->current / this->total * this->barWidth;
	std::cout << this->name << ": ";
	std::cout << "[";
	for(int i = 0; i < barWidth; ++i)
	{
		if (i < pos) std::cout << "=";
		else if (i == pos) std::cout << ">";
		else std::cout << " ";
	}
	std::cout << "] " << int(100. * this->current / this->total) << " %\r";
	std::cout.flush();

}

Progressbar::~Progressbar() {
	// TODO Auto-generated destructor stub
}

} /* namespace HDDTest */
