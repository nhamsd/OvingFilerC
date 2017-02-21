#include <iostream>
#include "utilities.h"
#include<cmath>


int randomWithLimits(int lower, int upper) {
	int random = (rand() % (upper-lower) + lower);
	return random;
}


