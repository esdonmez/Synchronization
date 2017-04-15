#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "registrar.h"
#include "bride.h"
#include "groom.h"
#include "extras.h"

void createParticipator();

pthread_t gtid, btid; // Groom thread / Bride thread
 
int main(int argc,char *argv[])
{
    pthread_t rtid1, rtid2, ctid;
    char command;
 
    // Semaphore initialization
    sem_init(&mutex, 0, 1);
    sem_init(&brides, 0, 0);
    sem_init(&grooms, 0, 0);
    sem_init(&registrars, 0, 2);

    // Thread creations
    pthread_create(&rtid1, NULL, (void *) registrar, (void *) 0); // Registrar 1
    pthread_create(&rtid2, NULL, (void *) registrar, (void *) 1); // Registrar 2
    pthread_create(&ctid, NULL, (void *) createParticipator, NULL); // Create groom and bride continuously
 
    while(1)
    {
    	scanf("%c", &command); // Get command
        if(command == 'q' || command == '\n') // Quit when q or enter pressed
        {
            exit(0);
        }
    }

    exit(0);
}

void createParticipator()
{	
	while(1)
	{
		int randomNumber = randomWait();

        if(randomNumber > 5) // If bigger than 5, create new participator
        {
            if(randomNumber % 2 == 0) // If even, create new groom
            {
                pthread_create(&gtid, NULL, (void *) groom, (void *)&indexGroom);

                printf("Groom is Created\n");
            }

            else if(randomNumber % 2 == 1) // If odd, create new bride
            {   
                pthread_create(&btid, NULL, (void *) bride, (void *)&indexBride);
        
                printf("Bride is Created\n");
            }
        }

        sleep(1);
	}
}
