/*
 * Configurator.h
 *
 *  Created on: Oct 21, 2014
 *      Author: root
 */

#ifndef SRC_CONFIGURATOR_H_
#define SRC_CONFIGURATOR_H_

namespace HDDTest {

class Configurator {
public:
	Configurator();
	virtual ~Configurator();

	void fetchConfigurations();
};

} /* namespace HDDTest */

#endif /* SRC_CONFIGURATOR_H_ */
