#include "Random.h"
#include<cstdlib>

/*will return a random number inclusive*/
int Random(int lowNumber, int hignNumber) {
	return lowNumber + rand() % ((hignNumber + 1) - lowNumber);
}