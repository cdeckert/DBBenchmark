/*
 * Randomizer.h
 *
 *  Created on: Nov 15, 2014
 *      Author: root
 */

#ifndef SRC_UTIL_RANDOMIZER_H_
#define SRC_UTIL_RANDOMIZER_H_
#include <random>


namespace HDDTest
{

class Randomizer
{
public:
private:
    static std::mt19937_64 rng;
public:
    static void seed(uint64_t new_seed = std::mt19937_64::default_seed) {
        rng.seed(new_seed);
    }

    static uint64_t get() {
        return rng();
    }
};

} /* namespace HDDTest */

#endif /* SRC_UTIL_RANDOMIZER_H_ */
