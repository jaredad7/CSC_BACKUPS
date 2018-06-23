/*
 *Does a vigenere cipher both encode and decode
 *Takes encode or decode input at the command line.
 *
 *@date <4.29.2014>
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

//4KB buffer size
#define KB4 4096

using namespace std;

void decode(char *key, int length);
void encode(char *key, int length);
//returns if the character is an uppercase letter
bool isUpper(char c);
//returns if the character is a lowercase letter
bool isLower(char c);

int main(int argc, char **argv)
{
	//parse command line -d decode, -e encode, also grabs key file name
	if(argc != 3)
	{
		cout << "Error, command line arguments invalid" << endl;
		return 0;
	}

	string arg = (string)argv[1];

	//Get the input key and its length
	char *in = argv[2];
	string k = in;
	int length = k.size();

	//Remove non-letter characters from the key
	//This is my key & This is my key! are equivalent
	for(int i = 0; i < length; i++)
	{
		//if the character is not lower or upper, remove it
		if(!isUpper(in[i]) && !isLower(in[i]))
		{
			length--;
			//shift left
			for(int j = i; j < length; j++)
			{
				in[j] = in[(j+1)];
			}
		}
	}
	
	if(arg == "-d")
		decode(in, length);	
	else if(arg == "-e")
		encode(in, length);
	else
		cout << argv[1] << ": Invalid Operation." << endl;

	cout << endl;

	return 0;
}

void decode(char *key, int length)
{	
	//create char buffer
	char input;
	
	//i tracks locaion in key
	int i = 0;
	//key is 0-x, length = x+1, make length = x
	length--;

	while(cin.get(input))
	{
		char p;
		//Until you reach end of key, then wrap
			
		//If uppercase letter or if lowercase letter, otherwise, character remains unchanged
		if(isUpper(input))
		{
			char c;
			if(isLower(key[i]))
				c = key[i] - 32;
			else
				c = key[i];

			p = abs(26 + input - c); 
			p = p % 26 + 'A'; 
		}
		else if(isLower(input))
		{
			char c;
			if(isUpper(key[i]))
				c = key[i] + 32;
			else
				c = key[i];

			p = abs(26 + input - c);
			p = p % 26 + 'a';
		}
		else
			p = input;

		cout << p;
			
		i++;
		if(i >= length)
			i = 0;
	}
}

void encode(char *key, int length)
{
	//create char buffer
	char input;
	
	//i tracks locaion in key
	int i = 0;
	//key is 0-x, length = x+1, make length = x
	length--;
	while(cin.get(input))
	{
		char p;
		
		//Until you reach end of key, then wrap
		if(isUpper(input))
		{
			char c;
			if(isLower(key[i]))
				c = key[i] - 32;
			else
				c = key[i];

			p = ((input - 'A' + c - 'A')%26 + 'A');
		}
		else if(isLower(input))
		{
			char c;
			if(isUpper(key[i]))
				c = key[i] + 32;
			else
				c = key[i];

			p = ((input - 'a' + c - 'a')%26 + 'a');
		}
		else
			p = input;

		cout << p;
		i++;
		if(i >= length)
			i = 0;

	}
}



bool isUpper(char c)
{
	return (c - 'A' >= 0 && c - 'A' <= 25);
}

bool isLower(char c)
{
	return (c - 'a' >= 0 && c - 'a' <= 25);
}

