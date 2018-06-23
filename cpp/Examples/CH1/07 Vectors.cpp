//Demostrate the power of vectors by asking some questions in random order
#include <iostream>//We know that this has cout and cin
#include <string>//Here are our strings from last time
#include <vector>//A new library, which contains vector functions
//#include <windows.h>
//#include <unistd.h>

using namespace std;

int random(int x);

int main()
{
    /*This is how we initialize a vector.
    Obviously, the word vector maens that it is a vector. Also, the thing
    inside the <> brackets is a data type (int, char, float, etc.) in this case, string
    question is the name of the vector, and (0) is how much space is in the vector.
    We will add space as needed to this vector, but there are ways if initializing
    with enough space before hand */
    vector<string> question(0);

    /*The function push_back() adds a
    new piece of data to the vector. Just as with arrays,
    this data is in position 0 in the vector*/
    question.push_back("What is my name?");
    question.push_back("What color is the sky?");//This does the same thing
    question.push_back("How many distinct digits in binary?");//This does the same thing0

    //Now we make a vector with the corresponding answers,
    //following the same steps as before
    vector<string> answer(0);
    answer.push_back("Jared");
    answer.push_back("Blue");
    answer.push_back("Two");
    
    /*Here is a while loop. This bit of code will be looped as long as
    the condition is met.  In this case, the condition is that the size of vector question,
    which is obtained from the function size().  The conditional operators are:

    != not equal to, == equal to, > greater than, < less than, >= greater than or equal to, <= less than or equal to*/
    while(question.size() != 0)
    {
        int number = (question.size()-1);
     
        string ans;//create a value type string
	
	//This code displays the value of the data 
        //contained in the 'number' position of the question vector
        cout << question[number] << endl;

        cin >> ans;//Get the user's answer
     
        if(ans == answer[number])
        {//check if the answer is right
             cout << "Right!" << endl;
             cout << "Removing Question." << endl;

             //use pop_back to erase the last piece of data in the vector.
	     //Vectors are a type of stack. Look up stacks as a data structure to
	     //learn more about stack and why the behave thise way.
             question.pop_back();
             answer.pop_back();
        }
        else
             cout << "Nope, try again!" << endl;
     }//This bracket ends the while loop
    
    //Sleep(5000);
    //sleep(5000);

    return 0;
}
