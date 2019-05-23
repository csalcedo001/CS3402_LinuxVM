#include <stdio.h>
#include <pthread.h>

#include "pthread_barrier.h"
#include "philosopher.h"

#define N_PHILOSOPHERS 5
#define N_STICKS 5
#define N_MAKIS 20
#define T_TALKING 4

pthread_barrier_t barrier;
pthread_mutex_t mutex;
int sticks = N_PHILOSOPHERS;
int totalTime = 0;
int finished = 0;
philosopher philosophers[N_PHILOSOPHERS];


void *prepareToEat(void *data) {
	int phIndex = (long) data;
	
	while (finished < N_PHILOSOPHERS) {
		pthread_mutex_lock(&mutex);

		if (sticks > 1 && !finishedEating(&philosophers[phIndex])) {
			sticks -= 2;
			
			printf("Filosofo %d esta comiendo\n", phIndex);

			--philosophers[phIndex].makis;

			if (philosophers[phIndex].makis == 0) {
				finished++;
			}

			pthread_mutex_unlock(&mutex);
		}
		else {
			printf("Filosofo %d esta hablando\n", phIndex);
			pthread_mutex_unlock(&mutex);
		}

		pthread_barrier_wait(&barrier);

		sticks = N_STICKS;

		pthread_barrier_wait(&barrier);

		if (phIndex == 0) {
			totalTime += 4;
		}
	}

	return NULL;
}

int main (void) {
	pthread_t threads[N_PHILOSOPHERS];

	sticks = N_STICKS;

	pthread_barrier_init(&barrier, NULL, N_PHILOSOPHERS);

	for (long index = 0; index < N_PHILOSOPHERS; index++) {
		philosopherInit(&philosophers[index], N_MAKIS);
		pthread_create(&threads[index], NULL, &prepareToEat, (void *) index);
	}

	for (int index = 0; index < N_PHILOSOPHERS; index++) {
		pthread_join(threads[index], NULL);
	}

	printf("Tiempo total: %.2f minutos\n", totalTime / 60.0);

	pthread_barrier_destroy(&barrier);

	return 0;
}
