/*
 *This is practice lesson #1.
 *Edit the code so that it compiles and runs without any bugs.
 *Each line details what it is trying to do, and it is up to you to get it to work properly.
 *Good luck, and don't hesitate to ask questions if you get stuck.
 */
#include <iostream>
#include <string>
#include <csdtlib>
#include <ctime>

//#include <windows.h>
//#include <unistd.h>

using namespace std;

int main()
{
	string input;
	//Get an input word
	cout << "Please input a word: "
	cin >> input;
	cout << endl;

	//Make a pointer to a new string
	string *pointer = new();

	//Set the value pointer points to equal to input
	pointer = input;

	//Reverse the order of input
	for(int i = 0; i < input.size(); i++)
	{
		input[i] = pointer[(input.size()+i)];
	}

	//Check whether or not the input string was a palindrome.
	//Be sure that the correct things are displayed to the user.
	if(input = *pointer)
		cout << "The input value: " << input << " was a palindrome!" << endl;
	else
		cout << "The input value: " << input << " was not a palindrome." << endl;
	
	//Sleep(5000);
	//sleep(5000);
	//exit the program
	exit();
}
