/*Pointers are a very useful and powerful tool.
 *The purpose of a pointer is to point towards a space in memory.
 *Basically, a pointer is a value in memory in HEXDEC (hexidecimal)
 *Form, such as 0xBADDAD, which 'points' to a specific location
 *in memory (which has the address, in this case, 0xBADDAD).
 *In order to illustrate this concept better, I have drawn a
 *diagram of it below.
 *
 *Name      Address      Value
 *pointer   0xFFD001     0x023FBD
 *integer   0x023FBD     365
 *
 *So, we can see in the diagram above, that the pointer's value
 *is the address of the integer in memory. It's ok if you cannot
 *see how this is useful yet. This concept won't often be used in
 *beginner-level programs. It is often used by people designing
 *device drivers or some other low-level applications, but it
 *is an important concept to master early on if possible.
 *So, let's see some practical examples.
 */
#include <iostream>
//#include <windows.h>
//#include <unistd.h>

using namespace std;

int main()
{
	//We set an int equal to five.
	int MyNumber = 5;
	/*Now, this line may be a bit confusing. Let's start with
	 *the left side. We declare a pointer by putting a * in front
	 *of it. This is just standard practice. Next, we need to set
	 *this pointer equal to our integer's ADDRESS. In order to get
	 *a variables address, we preface it with a &.
	 */
	int *p = &MyNumber;

	//Let's check that we did this properly.
	//These values do not necessarily need to be the same ones each 
	//time we run the program, but they must match each other in
	//each run through.
	cout << "The address of MyNumber is: " << &MyNumber << endl;
	cout << "The value of p is:          " << p << endl;

	//Now, let's 'dereference' p.
	//Dereferencing a pointer simply means
	//'get the value which is stored at its stored memory address.
	//In this case, the dereferenced value of p should equal MyNumber's
	//value.
	cout << endl << "MyNumber is: " << MyNumber << endl;
	cout << "p points to: " << *p << endl;

	//If we do not want a variable, we can point a pointer to a 
	//new space in memory, thus bypassing the variable entirely.
	//We can then use the dereferencing property of pointers in
	//reverse to alter the value stored in the new space.
	int *p2 = new int;
	*p2 = 10;

	//Let's be sure that this pointer has the correct value.
	cout << endl << "p2 points to: " << *p2 << endl;

	/*When we are finished with variables created in this new way,
	 *we can reuse the pointers. For example, say that I now want
	 *to assigned MyNumber's address to p2. I can forget about the
	 *old space and assign the pointer a new address.
	 *BUT BEWARE!!! If you are going to do this, you need to keep
	 *in mind a very important property of c++. That is, it holds
	 *on to the memory your OS assigns it (the new space we gave to
	 *the pointer). In order to remove this space from memory, we need to
	 *delete the pointer. This doesn't delete the pointer itself, but it
	 *releases the space in memory back to the OS to be used somewhere it 
	 *is actually needed, instead of being held onto until this program
	 *ends. Let's look at an example.
	 */
	delete p2;

	//p2 still has the same value, but, if we try to access it, the OS
	//will complain that we don't have permission, since we gave it up,
	//and we will get a Segmentation Fault, and our program will crash.
	//It is proper practice to set pointers to NULL if their current value
	//is no longer in use by the program, to avoid such mistakes.
	p2 = NULL;

	//Of course, we now want to set it equal to MyNumber's address, so setting
	//p2 to NULL was strictly for example in this case.
	p2 = &MyNumber;

	//Let's ensure that we did this correctly.
	cout << endl << "p2 now points to: " << *p2 << endl;

	/*Pointers can be very finicky, and they like to cause us Segmentation Faults,
	 *which most CS people have come to despise. You need to be very careful when
	 *using pointers, to ensure that you are not doing anything harmful to your
	 *program.
	 */
	

	//Sleep(5000);
	//sleep(5000);
	return 0;
}
