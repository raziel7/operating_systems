/*
 * DNeckaSO4second.c
 *
 *  Created on: May 3, 2016
 *      Author: raziel
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define true 1
#define false 0

int main(int argc, char* argv[])
{
		if(argv[1]!=NULL)
		{
			int charInLineCounter=0, intAfterInt=0, strings=0;
			int stringLength = atoi(argv[1]);
			char character;
			time_t start=time(NULL), end=time(NULL);

			while(!feof(stdin))
			{
				while(end-start < 5)
				{
					end = time(NULL);
					charInLineCounter++;

					fread(&character, sizeof(char), sizeof(char), stdin);
					if(character>='0' && character<='9')
					{
						intAfterInt++;
						if(intAfterInt==stringLength)
						{
							intAfterInt = 0;
							strings++;
						}
					}else
					{
						intAfterInt = 0;
					}

					if(charInLineCounter%16 == 0)
					{
						charInLineCounter = 0;
						intAfterInt = 0;
					}
					fflush(stdin);
				}

				printf("For string length of: %d\tThere was: %d strings of numbers\n", stringLength, strings);
				break;
			}
		}

	return EXIT_SUCCESS;
}
