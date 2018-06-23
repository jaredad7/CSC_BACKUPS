/*
 *Program to decrypt Gourd's plaintext
 *Take the key in from a file called key in current directory
 *@author <Jared Dembrun>
 *@date <4.9.14>
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//Open File
	ifstream File("key");

	//Get the length of the file
	File.seekg (0, File.end);
    	int length = File.tellg();
    	File.seekg (0, File.beg);

	//create char buffers
	char input[length];
	char key[length];

	//Get both inputs
	cin.get(input, length);
	File.read(key, length);
	
	//Decrypt and print output
	for(int i = 0; i < length; i++)
	{
		char out = input[i] ^ key[i];
		cout << out;
	}
	return 0;
}
