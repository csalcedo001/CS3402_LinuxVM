#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *printHola(void *num_hilo) {
	long t;
	t = (long) num_hilo;
	printf("Hola Mundo! Desde el hilo %ld \n", t);
	pthread_exit(NULL);
}

void callThread(long n) {
	pthread_t hilo;
	int rc = pthread_create(&hilo, NULL, printHola, (void*) n);

	if (rc) {
		printf("ERROR\n");
		exit(-1);
	}
}


int main() {
	int i, j, k, rc;
	long t;

	pthread_t hilo0, hilo1;

	printf("Bienvenidos a HOLAS \n");

	t = 0;
	for (t = 0; 1; t++) {
		rc = pthread_create(&hilo0, NULL, printHola, (void*) t);
	
		if (rc) {
			printf("ERROR\n");
			exit(-1);
		}
	}
	
	pthread_exit(NULL);
	return 0;
}
