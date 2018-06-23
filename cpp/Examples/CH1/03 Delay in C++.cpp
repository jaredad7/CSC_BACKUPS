//display a text for 5 seconds
#include <iostream>

//These libraries contain platform-specific calls, such as Sleep(x)
//in windows.h and sleep(x) in unistd.h, for UNIX machines.
//You will have to uncomment the proper one for your machine
//as well as the corresponding line below in the main fuction
//#include <windows.h>
//#include <unistd.h>

using namespace std;

int main()
{
    /*Here is a 'for' loop.  This loop begins
    by initializing some value. Then, it sets a limit for that value. Then, it is
    given a command for each 'iteration' of the loop. This means that something will
    happen to the given value each time the loop happens, and the loop will occur 
    until the condition is no longer met.*/
    for(int i = 0; i < 5; i++)
    {
        cout << "Your code is good!!!!" << endl;
	//sleep and Sleep take their parameters in milliseconds, so let's sleep for 5 seconds.
	//uncomment Sleep(5000); for windows and sleep(5000); for unix-systems
        //Sleep(5000);
	//sleep(5000);
    }
    return 0;
}
