//Let us introduce strings
#include <iostream>
#include <string>//We will need this library

//#include <windows.h>
//#include <unistd.h>

using namespace std;

int main()
{
	//We will declare a type called a 'string'
	//A string is like an array of char, but it has some added functionality,
	//which makes it very useful. One such functionality is the size() function.
	//Another perk of strings is that they are dynamically allocated,
	//which means we don't need to know their size beforehand.
	string word;
	cout << "Enter a word" << endl;
	cin >> word;
	cout << "Your word was: " << word << endl;
	//With what you've learned so far, you should be able to figure out what 
	//Happened in the lines above this.

	//Let's do something to the string now.
	//Since a string is basically just a character array, we can
	//access its members the same way. The size function is access with word.size()
	//because of what strings actually are: classes. We will learn more about classes
	//in a later lesson.
	for(int i = 0; i < word.size(); i++)
	{
		int out = word[i];
		cout << "The ASCII value of letter " << i << " in your word is " << out << endl;
		//As a side note, recall that characters are simply stored as their ascii values, 
		//and we can extract these values with an 'int'. We do this here.
		//Run this code and see what the ascii values of certain characters are.
	}

	//Sleep(5000);
	//sleep(5000);	
	return 0;
	//You should do some more research on strings in C++ to learn more about
	//their functionality and usefullness.
}
