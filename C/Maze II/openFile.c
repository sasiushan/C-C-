#include<stdio.h>
#include<stdlib.h>

int read(char * argv[])
{
	FILE * f = fopen(argv[1], "r");
	int ch; 
	if(f == NULL)
	{
		perror("fopen");
	}
	else
	{
		fscanf(f, "%d", &ch);
		while(!feof(f))
		{
			printf("%d\n", ch);
			fscanf(f, "%d", &ch);
		}
	}
	fclose(f);
	return 0;
}		
	