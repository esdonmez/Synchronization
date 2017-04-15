#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "groom.h"
#include "extras.h"

void groom(void *arg)
{
    sem_wait(&mutex);
    numGroom++; // Increment groom number
    indexGroom++; // Index for thread creation
    printf("Grooms : %d\n", numGroom);
	printf("Brides : %d\n", numBride);
	printf("Married Couples : %d\n", numCouple);
	printf("-------------------------\n");
    sem_post(&mutex);
    sem_post(&grooms);
    sem_wait(&registrars);
}
