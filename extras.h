#include <semaphore.h>
#ifndef definitionsh
#define definitionsh
extern int indexGroom, indexBride, numGroom, numBride, numCouple;
extern sem_t mutex, brides, grooms, registrars;
int randomWait();
void printables(int);
#endif
