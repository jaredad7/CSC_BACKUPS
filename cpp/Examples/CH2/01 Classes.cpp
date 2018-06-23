#include <iostream>

using namespace std;

//First, we declare our class. Refer to the Chapter Introduction to learn what a class is.
class SimpleClass
{
/*We declare anything that comes after this 'private' declaration as private
 *This means that functions outside of our class will not be allowed to access anything called 'private'
 *Both functions and variables may be declared private or public.
 */
private:
	int age;
/*Public is simply the opposite of private, that is, any function can access these functions and variables.
 *Because these functions are within the class, they can access the private variables and functions.
 *We call all variables and functions in a class, both private and public, member variables and functions.
 */
public:
	//This is called a constructor. It is called when the class is first instantiated, and it is used to
	//Do some setup. All constructors are the same name as the class, and have no function type, like void or int
	SimpleClass()
	{
		age = 0;
	}
	//This function is used to change the private variable
	void grow()
	{
		age++;
	}
	//This function is used to examine the private variable
	int get_age()
	{
		return age;
	}
};//Remember to finish your classes with a semi-colon. The compiler will complain, otherwise

int main()
{
	//Here, we instantiate a SimpleClass object called s1.
	SimpleClass s1;
	//You've seen these dots with strings and vectors. They are used to access member variables and functions of a class
	int a = s1.get_age();
	
	while(s1.get_age() < 70)
	{
		s1.grow();
		cout << "The simple class is now " << s1.get_age() << " units old." << endl;
	}

	cout << "The simple class has reached the end of its life." << endl;

	return 0;
}
