/*This code is an example of an array
 *An array is a 'container. It allows us to store values of one
 *type in a long list.
 */
#include <iostream>

//#include <windows.h>
//#include <unistd.h>

using namespace std;

/*This is called a templated function. It can take any type of
 *Data and do things with it. The 'dtype' is simply a placeholder for
 *char, int, float, etc...
 *The function returns a boolean value, which is true if a > b and
 *false if b >= a.
 */
template <class dtype>
bool great(dtype, dtype);

int main()
{
	/*First, we declare a new array of type 'int'
	 *We set the array's size to 5.
	 *This must be done because the array's size is static, meaning
	 *that it does not change.
	 *Since computers use pure logic, the indexes
	 *available in the array will be 0-4.
	 *The term 'index' refers to an element's position in the array.
	 *More on this later.
	 */
	int arr[5];

	/*Next, let's use a for loop to add values to the array.
	 *We will access the array's index with arr[i], where
	 *i is the index. If we try to go beyond the array's
	 *size, we will get a 'segmentation fault' or 'seg fault',
	 *which means that our program tried to access some
	 *memory (RAM) which was not allocated to it.
	 *
	 *There are a few different kinds of loops. This kind
	 *is called a for loop, and understanding it is quite simple.
	 *The part before the first semi-colon is used to set an
	 *iterator. We can declare the iterator here, or above the loop if we like.
	 *If we declare it above the loop, we can refer to it afterwards. Otherwise,
	 *If we declare it here, it gets thrown away at the end.
	 *
	 *The second part is the condition. As long as the condition is true,
	 *the loop will execute again.
	 *
	 *Finally, we have the third part, which is simply the thing that happens
	 *each time the loop ends. Since we increment i each time, it will eventually
	 *beomce greater than or equal to (>=) 5, and the loop will end.
	 */
	for(int i = 0; i < 5; i++)
	{
		arr[i]=((i+1)*5);
	}

	//Next, we will print the values at the array's indexes, one by one.
	//Can you guess what they will be?
	for(int i = 0; i< 5; i++)
	{
		cout << arr[i] << endl;
	}

	/*Let's now use the template two different ways.
	 *First, let's send two ints.
	 *Second, let's send two characters.
	 */
	if(great(arr[2], arr[1]))
		cout << "a is greater." << endl;
	else
		cout << "b is greater." << endl;

	//Now, two characters:
	if(great('A', 'a')) //Little a should be greater than big A because its ASCII value (a number the computer knows corresponds to a character)
			    //is geater.
		cout << "a is greater." << endl;
	else
		cout << "b is greater." << endl;

	//Sleep(5000);
	//sleep(5000);
	return 0;
}

template <class dtype>
bool great(dtype a, dtype b)
{
	/*All comparison statements (the kind we used for if 
	 *statements) return some boolean value, thus allowing us to write this
	 *function in one line, as follows.
	 */
	return (a > b);
}
