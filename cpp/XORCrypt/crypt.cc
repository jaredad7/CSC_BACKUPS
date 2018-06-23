/*
 *Exclusive or a number input with a random int from the rand() function
 *This will create an encrypted file version of the file
 *Users can add security by selecting a unique seed which will be used
 *to change the default xor key.
 *In order to decrypt the file, users must know this input seed.
 *Each 
 *
 *@author<Jared Dembrun>
 *@date<4.8.14>
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void help();

int main(int argc, char **argv)
{
	//Verify personal seed or default seed
	//If argument -h is present, display help
	char input;
	
	//Get the password
	if(argc != 1)
	{
		long in = 0;
		string arg = argv[1];
		for(int i = 0; i < arg.size(); i++)
		{
			in += (long) arg[i];
			if(!strcmp(argv[1], "-h"))
				help();
		}
		srand(in);
	}
	else
		srand(0);

	//encrypt file
	while(cin.get(input))
	{	
		char key = rand();
		char out = input ^ key;
		cout << out;
	}
	return 0;
}
//Display help and exit gracefully
void help()
{
	cout << "This program will encrypt your files with a default key seed of 0." << endl;
	cout << "To change this seed, enter a new seed as an argument. Example program call:" << endl;
	cout << "crypt s 3 3 d < filename.in > filename.out" << endl;
	cout << "Be sure to inlude a space between each character of your personal seed." << endl;
	cout << "To decrypt a file, simply run it back through the program with the same seed." << endl;
	exit(0);
}
