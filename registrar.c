#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "registrar.h"
#include "extras.h"

void registrar(void *arg)
{   
    while(1)
    {
        sem_wait(&brides);     
        sem_wait(&grooms);  
        sleep(randomWait()); // Wait marriage  
        sem_wait(&mutex);
        numGroom--; // Decrement groom
        numBride--; // Decrement bride
        numCouple++; // Increment couple
        printf("Grooms : %d\n", numGroom);
        printf("Brides : %d\n", numBride);
        printf("Married Couples : %d, Registrar Number %lu\n", numCouple, (long unsigned int)arg);      
        printf("-------------------------\n");
        sem_post(&mutex);
        sem_post(&registrars);     
    }
}
