#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int status = 0;
	pid_t shareMem, getMem;

	shareMem = fork();
	if(shareMem==0)
	{
		execl("SharedMemory", 0);
		exit(EXIT_FAILURE);
	}else if(shareMem==-1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}

	getMem = fork();
	if(getMem==0)
	{
		execl("GettingSharedMemory", 0);
		exit(EXIT_FAILURE);
	}else if(shareMem==-1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}

	if(wait(&status)==-1)
	printf("Error waiting\n");

	else
	{
		if(WIFEXITED(status))
			if(WEXITSTATUS(status) == 3)
			{
				printf("server stopped, exiting client\n");
				kill(getMem, SIGTERM);
			}
	}

	exit(0);
}
