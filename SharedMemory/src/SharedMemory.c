/*
 ============================================================================
 Name        : SharedMemory.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
	srand(time(NULL));

	int size = 40;

	//Shared memory
	int shmid, i;
	long *buf;
	shmid = shmget(45281, size*sizeof(char), IPC_CREAT|0600);

	if(shmid == -1)
	{
		perror("Creating shared memory");
	}

	buf = (long*)shmat(shmid, NULL,0);
	if(buf == NULL)
	{
		perror("Attaching shared memory segment");
		exit(1);
	}

	//---------//
	long p = 2;
	int q = 2;

	char a;
	for(i=0;i<size;i++)
	{
		p *= q;
		buf[i] = p;
	}

	return EXIT_SUCCESS;
}
