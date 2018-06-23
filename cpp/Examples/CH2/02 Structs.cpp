#include <iostream>
#include <cstring>

using namespace std;

//A struct is an abstract container for information.
struct person
{
	//A struct only contains variables, no functions, since its purpose is to contain data
	string name;
	int age;
	int height;
};//Like a class, a struct definition should end with a semi-colon

int main()
{
	//We instantiate our person struct
	person p;
	
	//Let's collect some data.
	//We simply access the struct's members with a dot, like a class, treating them as ordinary variables.
	//Note that this means a struct's variables are essentially all public.
	cout << "What is your name? ";
	cin >> p.name;

	cout << "What is your age? ";
	cin >> p.age;

	cout << "What is your height in inches? ";
	cin >> p.height;

	//Let's show that we have successfully stored the data by displaying it.
	cout << "Your name is " << p.name << ", your age is " << p.age << "," << endl;
	cout << "and your height is " << p.height << "in." << endl;

	return 0;
}
