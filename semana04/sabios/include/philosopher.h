#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <pthread.h>

typedef struct philosopher {
	pthread_t thread;
	int makis;
} philosopher;

char finishedEating(philosopher *);
void philosopherInit(philosopher *, int);

#endif
