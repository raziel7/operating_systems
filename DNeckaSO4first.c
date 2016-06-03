/*
 ============================================================================
 Name        : DNeckaSO4.c
 Author      : Raziel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0

int main(void) {

	srand(time(0));

	int i = 0;
	time_t start = time(NULL), end = time(NULL);
	char character;

	while(true)
	{
		while(end-start < 5)
		{
			end = time(NULL);
			while(true)
			{
				i = (rand()%'Z');
				if((i>='0' && i<='9') || (i>='A' && i<='Z'))
					break;
			}
			character = (char)i;
			fwrite(&character, sizeof(char), sizeof(char), stdout);
			fflush(stdout);
		}
		break;
	}

	return EXIT_SUCCESS;
}
