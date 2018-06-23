//Randomizing values using the rand()
#include <iostream>
#include <cstdlib>/*This library contains the rand(), which 
generates a random number between 0 and the constant RAND_MAX
This generated value typically generates in sequential order,
but we can 'seed' the generator using the next library */
#include <ctime>//This library knows what time it is
//we can use this library to pick a random value based on time

//CHECK THESE AGAIN
//#include <windows.h>
//#include <unistd.h>

using namespace std;

void randomNumber();/*Here's something totally new. BAM!! This helpful
little guy is called a function. You may recognize that it ends in parentheses,
much like int main() or Sleep().  That is how we can tell that it is a function.
Up here, before int main(), I create what is called a function prototype.
After int main(), I will define the function, or tell the compilier
What the function will do when called during int main().  This function is called
'void' because it will not return a value*/
int randomNumberTo100(int number);/*This funtion is a little bit different.  First of all, 
it is an 'int' type, which means that it will return an 'int' value. During int main(),
we can set some int variable equal to the value which randomNumberTo100 returns.
The integer defined as number inside of the parentheses is called a parameter
The function will receive this parameter from another value given to it in int main()
More on functions in the actual functions.*/

int main()
{
    srand(time(0));//this function 'seeds' the random number generator
    //and picks a value based on the current time
    randomNumber();
    int number = rand();
    int Nnumber = randomNumberTo100(number);//much like Sleep(x),
    //the function will receive the value and do something with it.
    //Also, we set Nnumber = randomNumberTo100(number);
    cout << Nnumber << endl;//this will display the returned value from the function


    //CHOOSE THE CORRECT ONE
    //Sleep(5000); //wait a bit before closing the program
    //sleep(5000); //wait a bit before closing the program
    return 0;//Hey, now you know what this menas!!!!
}

void randomNumber()
{
     srand(time(0));/*I have to re-seed the generator because it was not seeded in this scope.
     A scope is any time you open up the { bracket. A scope does not keep track of anything created within scopes within itself
     However, it will check the things in the scopes outside of it.
     I know that sounds complicated, but basically, if the compilier ever tells you that a value was
     not defined within a scope, try defining it closer to the beginning of the function or 
     re-define it within the problem-scope*/
     int number = rand();
     cout << number << endl;//display the randomly generated number
}

int randomNumberTo100(int number)
{//this function, upon receiving some value, will assign that value
//to int number. Then, we an use number in the function

     number %= 100;/*A couple of things happen here.  First, we are using % as an opperator.
     This operator will divide the left hand side by the right hand side and take the remainder.  This is useful for getting
     random numbers in a certain range. We also use this operator in conjunction with an =.
     By doing so, as with any operator used this way, we are telling the compiler to set
     number equal to itself operator whatever is on the right hand side.
     For a simpler example, if int a = 3, then a += 2 sets a = 5, or 3+2.*/
     return number;//This will return the value of number to int main().
}
