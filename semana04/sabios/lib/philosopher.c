#include "philosopher.h"

char finishedEating(philosopher *ph) {
	return ph->makis <= 0;
}

void philosopherInit(philosopher *ph, int makis) {
	ph->makis = makis;
}
