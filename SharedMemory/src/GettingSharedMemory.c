#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	int size = 40;
	int shmid, i, counter=0;
	long* buf;

	clock_t start = clock();

	shmid = shmget(45281, size*sizeof(char), IPC_CREAT|0600);
	if(shmid==-1)
	{
		perror("Creating shared memory segment");
		exit(1);
	}

	buf = (long*)shmat(shmid, NULL, 0);
	if(buf==NULL)
	{
		perror("Attaching shared memory segment");
		exit(1);
	}

	for(i=0;i<size;i++)
		printf("Character number: %d Value: %li\n", i, buf[i]);

	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Done in: %f seconds\n", seconds);

}










