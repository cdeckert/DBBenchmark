/*
 * Drive.h
 *
 *  Created on: Oct 30, 2014
 *      Author: root
 */

#ifndef SRC_TESTS_DRIVE_H_
#define SRC_TESTS_DRIVE_H_
#include <unordered_map>
namespace DBTest {

class Drive {
public:
	static Drive* get(std::string);
private:
	static std::unordered_map<std::string, Drive*> drives;
	Drive(std::string);
	virtual ~Drive();
};

} /* namespace DBTest */

#endif /* SRC_TESTS_DRIVE_H_ */
