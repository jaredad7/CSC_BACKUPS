/*
test if for(int i = 0;... is legal
that would be big fat NO
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	for(i = 0; i < 10; i++)
		printf("Success!\n");
	exit(0);
}
