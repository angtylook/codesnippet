#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <stdlib.h>
#include <time.h>

class RandomGenerator {
    public:
        RandomGenerator() {
            srand(time(NULL));
        }
        unsigned int getNextInt(unsigned int l, unsigned int h) {
            return rand() % (h - l) + l;
        }

        bool getNextBool(double h) {
            int c = rand() % 10;
            if(c <= h * 10)
                return true;
            else
                return false;
        }
};


#endif