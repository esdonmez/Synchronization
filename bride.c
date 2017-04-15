#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <stdbool.h>
#include "bride.h"
#include "extras.h"

void bride(void *arg)
{
    sem_wait(&mutex);
    numBride++; // Increment bride
    indexBride++; // Index for thread creation
    printf("Grooms : %d\n", numGroom);
	printf("Brides : %d\n", numBride);
	printf("Married Couples : %d\n", numCouple);
	printf("-------------------------\n");
    sem_post(&mutex);
    sem_post(&brides);
    sem_wait(&registrars);
}
