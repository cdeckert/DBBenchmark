/*
 * Progressbar.cpp
 *
 */

#include "Progressbar.h"


namespace HDDTest
{

Progressbar::Progressbar(std::string name, uint64_t total)
{
	this->total = total;
	this->current = 0;
	this->barWidth = 70;
	this->name = name;
	this->old = -1;

}

void Progressbar::add(uint64_t addition)
{

	this->current = this->current + addition;
	int prg = int(100. * this->current / this->total);
	if (prg != old)
	{
		int pos = 1. * this->current / this->total * this->barWidth;


		std::cout << this->name << ": ";
		std::cout << "[";
		for (int i = 0; i < barWidth; ++i)
		{
			if (i < pos) std::cout << "=";
			else if (i == pos) std::cout << ">";
			else std::cout << " ";
		}
		std::cout << "] " << prg << " %\r";
		std::cout.flush();
		this->old = int(100. * this->current / this->total);
	}
}

Progressbar::~Progressbar()
{
	// TODO Auto-generated destructor stub
}

} /* namespace HDDTest */
