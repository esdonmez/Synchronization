#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int indexGroom, indexBride, numGroom, numBride, numCouple;
sem_t mutex, brides, grooms, registrars; // Semaphores

int randomWait() // Generate random number
{
    srand(time(NULL));
    int randomWaitTime = rand() % 10 + 1;
    return randomWaitTime;
}