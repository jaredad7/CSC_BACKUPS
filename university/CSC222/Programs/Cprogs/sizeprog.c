/*
	Print out the byte size of many c types
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("The sizes of a few different types\n");
	printf("Float: %d Double: %d Int: %d\n", sizeof(float), sizeof(double), sizeof(int));
	printf("Long: %d Short: %d Char: %d\n", sizeof(long), sizeof(short), sizeof(int));
	//printf("Bool: %d\n", sizeof(bool));
	exit(0);
}
