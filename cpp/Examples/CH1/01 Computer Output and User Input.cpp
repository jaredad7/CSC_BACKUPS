//Hello World
//How to write output and receive input
//two slashes begin a comment which is ignored by the compiler when the code is put together
/*
 *a slash star is a multi-line comment. It ends with a star slash.
 */
#include <iostream>/*This library contains 'cout' and 'cin', which are necessary in nearly every program.
It also includes some other functions that interact with the console, the little command window that
opens when your program starts up. */

/*if you didn't use this, you would basically have to add std:: before everything you wrote
Thus, cout << "Hello World" << endl; becomes std::cout << "Hello World" << std::endl; */ 
using namespace std;

//main() is required in every program. It is used to begin and to end. '{' begins its definition
int main()
{
    //cout << writes whatever is 'funneled' or <<'ed to it. << endl; is funneled to 'cout' to
    //begin a new line in what is written.  Anything can be written between quotes. We call this a string.
    cout << "Hello World" << endl;

    //no 'endl' here because we want to use the same line.  However, every
    //line of code must end in a semi-colon.
    cout << "Please enter a character: "; 

    /*This creates a variable called 'input'.  'char' denotes the type of variable as a character.
    Some other common variable types are 'int', which creates an integer, and 'bool', which stands for
    boolean and creates a variable which can be either true or false*/
    char input; 

    //'cin' funnels the user's input character to the variable called 'input'.
    cin >> input; 

    /*So, we see here that you can also funnel a varibale type to cout.  
    \n is a shortcut which means 'begin a new line', and it can be placed anywhere within the string, or between quotes.
    another one of these shortcuts is \t, which tabs right five spaces. These are not actually written in the text box.*/
    cout << "\nYou wrote " << input << endl;

    //Here, we call main() in order to loop the function.  by doing so, the program goes back up to the beginning
    main();

    //Since main() is an integer function, it must return some integer.  When main() returns 0, it
    //simply means that the program is complete.  However, this program will never return 0. Can you guess why?
    return 0;

}//We close this bracket to denote the end of main()'s definition
