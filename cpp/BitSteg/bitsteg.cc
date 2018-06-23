/*
 *Replace the least significant bit in each byte of the file with a message component bit
 *USER WARNING: assumes the container file is large enough to contain the message (8*message size + offset)
 *
 *Will use an input file called message by default to encode in the container
 *The -decode option will decode a file (from start to finish) and print it
 *@author <Jared Dembrun>
 *@date <4.28.2014>
 */
#include <iostream>

//The offset in number of bytes
#define OFFSET 4096

using namespace std;

void decode();
void encode();

int main(int argc, int **argv)
{
	//parse command line
	for(int i = 0; i < argc; i++)
	{
		if(argv[i] == "-decode" || argv[i] == "-d")
			decode();	
	}
	//encode if no -decode command
	encode();
	return 0;
}

void decode()
{
	
}

void encode()
{
	
}
