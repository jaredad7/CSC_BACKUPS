/*Using C++ to do some math
What good is a program without math?  Absolutely worthless!
So, if your program doesn't at least do some amount of calculation,
then it's not really producing anything worth-while
let's see how to have C++ do some basic calculations on user-input*/
#include <iostream>

using namespace std;

int main()
{
    /*Wait, what's a float?  Well, an integer can only be a number which has no decimal, but you could be dividing here.
    A float value is simply a numeric value which is allowed to use decimals.  Sure, I could call 'c' an integer,
    but the program would simply drop whatever came after the decimal; we call this "truncating". For example: if a=2 and b=3, 
    then a/b = c = .66667, but, an integer c would drop whatever came after the decimal, making c = 0, which just isn't right. 
    Another way to handle this is by typecasting a as a float when it is actually an integer. We will discuss this in detail later.*/
    float a;

    //b is also a float.  Both variables have not been assigned values
    float b;

    //This character will be + - / or *, and it will denote the operation on the two integers
    char opp;
    cout << "Please input a first integer: ";
    cin >> a;//receives the value for 'a'
    cout << "Please input a second integer: ";
    cin >> b;//receives the value for 'b'
    cout << "Please enter +,-,/, or *: ";
    cin >> opp;

    /*Now, it's time to use some conditional statements.  Since the possibility exists for 
    Four operations, there should be four conditional statements.  However, some people like
    to try to glitch programs by entering incorrect infomation, so we need another conditional statement
    to deal with this problem*/
    
    float c;//Let's declare another variable.
    
    if(opp == '+')
    {/*The statemet 'if' tells the computer to check whether or not the following statement,
    in this case, opp == +, is true.  Two equal signs are required here because, with one equal sign, the
    compilier thinks that you are trying to set opp = +, and that's just not right.
    Anytime you use a charater, the charater itself must be inside of apostrophes.  
    Without these, 'a' might be mistaken for variable float a.
    The bracket is not necessary here, because only one line of code follows the condition. However,
    if you want more code to follow the condition, you need this bracket. It's good to be in the habit
    of always putting it there*/
         c = (a + b);//let's do some math to define c
    }
    else if(opp == '-')
    {/*the else here denotes that this satement will be checked if and only if the if statement
    above is untrue. If this were just an if, then the program would check if both were true, and it would run both if both
    were true. Although it is immpossible for opp to equal both + and -, but, again, this is a good habit to have*/
         c = (a - b);//Again, we do some math to define c.  
    }
    else if(opp == '/')
    {    /*Here, had a and be been declared as integers, we could write the following code:
         c = (float)(a/b);  this would make c receive the value of a/b untruncated.
	 Doing this is called 'typecasting', and it can be done for any compatible types.*/
         c = (a/b);
    }
    else if(opp == '*')
    {
         c = (a*b);
    }
    else
    {//huh? there's no if after this else. That's because this else runs if all of the other else if's and the initial if are not true
    //it's actually really useful!
         cout << "You cannot defeat my awesome code!" << endl;/*this statement is untrue. One could simply enter
         a  non-numeric value for one of the integers or floats in any program. Also, if any input value or the value of 'c' 
         excedes a certain limit, then the float type will be unable to handle it.  There is another type of float called double, 
         which can handle much larger numbers.  It, too, is limited. */ 
    }
    
    cout << c << endl;//this will display the caluculated value
    
    main();//Again, we want to loop this program
    return 0;
}
