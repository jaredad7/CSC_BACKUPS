/*In this lesson, we will run some tests on our Linked List,
 *ensuring that it runs correctly.
 *
 *First, we need to include the Linked List. We have included many things
 *in previous lessons, like iostream, windows.h or unistd.h, vector, string, etc.
 */

#include <iostream>
#include <cstring>//Arrow brackets include something from the c library, which is in different directories on different computers.
#include "03 Linked List.cpp" //The quotes are used to include something in the same directory as this file.

int main()
{
	//Let's begin by making a list of integers
	LinkedList<int> intList;

	//We will run some tests to make sure our list acts as expected
	//First, we should get back null, which an intList will see as zero
	cout << intList.getCurrent() << endl;
	intList.add(3);
	intList.add(1);
	intList.add(45);
	intList.add(12);

	//Current should be at the head
	cout << intList.getCurrent() << endl;
	
	//Next will print the next value and move to it
	cout << intList.next() << endl;
	intList.print();

	//Let's move current to a particular data type
	//We should get back a 0, confirming that it was found
	cout << intList.setCurrent(45) << endl;
	cout << intList.getCurrent() << endl;

	//Let's move current to a particular position
	intList.setCurrentPos(0);
	cout << intList.getCurrent() << endl;

	//Let's try to move past the highest node.
	intList.setCurrentPos(5);
	intList.print();

	//Let's ask the list to find a data which is not in it. We should receive a -1
	cout << intList.setCurrent(56) << endl;
	intList.print();

	//Let's remove all of the data and then try to getCurrent
	//First we'll look at the size, then again after we remove things
	cout << intList.size() << endl;
	intList.remove();
	intList.remove();
	intList.remove();
	intList.remove();
	cout << intList.size() << endl;
	cout << intList.getCurrent() << endl << endl;//Two newlines

	//Now we know that our list works properly. Can you think of other tests we might
	//be able to run to ensure the list runs without problems?

	//We can also use our Linked List to store other types, like char, float, etc.
	//We can even store objects, like strings.
	LinkedList<string> strList;
	strList.add("Hello");
	strList.add("Goodbye");
	strList.add("I <3 programming.");

	strList.print();
	strList.setCurrent("Goodbye");
	strList.print();

	return 0;
}
