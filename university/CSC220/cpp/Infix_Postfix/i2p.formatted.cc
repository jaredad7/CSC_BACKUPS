/*******************************************************************************************************
Jared Dembrun
10/30/13

i2p.cc, converts infix expressions to postfix and solves them
********************************************************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>
#include "GenericList.cc"
#include "Stack.cc"
#include "Queue.cc"

using namespace std;

void clear(char[MAX_SIZE]);
Queue<char> infix_builder(char[MAX_SIZE]);
void post_builder(Queue<char>&);//builds the postfix queue
void next_char(Queue<char>&, char);//find the next character's place in the queue
double solution(Queue<char>&);//Solves the equation
bool notop(char);//returns true if the char is not an operator
bool priority(char, char);//returns true if char a has a higher priority than or equal priority to char b

int main()
{
	char input[MAX_SIZE];

	//erase all values contained by input
	clear(input);

	//main loop, read each line and process them, one at a time
	while(cin.getline(input, MAX_SIZE))
	{
		Queue<char> mainq = infix_builder(input);//create a queue from the input line
		//cout << "Printing input: " << endl;
		cout << mainq << endl;

		post_builder(mainq);//create the postfix queue
		//cout << "Printing infixed: " << endl;
		cout << mainq << endl;

		cout << solution(mainq) << endl << endl;//solve the equation and print the answer

		//cleanup
		clear(input);
	}
	return 0;
}

//clear the char array
void clear(char input[MAX_SIZE])
{
	//set all values of a char array of MAX_SIZE to spaces
	for(int i = 0; i < MAX_SIZE; i++)
		input[i] = ' ';
}

//Create a queue from the input data
Queue<char> infix_builder(char input[MAX_SIZE])
{
	Queue<char> q;
	for(int i = 0; i < strlen(input)/*((input[i] != ' ') && (i < MAX_SIZE))*/; i++)
		q.Enqueue(input[i]);
	return q;
}

void post_builder(Queue<char> &q)
{
	Queue<char> p;//The postfix queue
	Queue<char> pq;//A prioritized queue of operators
	//char saved1 = ' ';//saves a character; spaces are empty
	//char saved2 = ' ';//saves a second character; no more than two characters should ever need to be saved
	//build a post-fixed queue
	while(!q.IsEmpty())
	{
		char next = q.Dequeue();
		if(notop(next))//if the character is not an operator
		{
			if(((next - '0') >= 0) && ((next - '0') <= 9))//filter out all non-arithmetic characters
				p.Enqueue(next);
		}
		else
		{
			if(pq.IsEmpty())//if it is empty
				pq.Enqueue(next);
			else if(next == ')')//if there is a close paren, empty all back to the open paren
			{
				char c;
				while((c = pq.Dequeue()) != '(')
					p.Enqueue(c);
				//discard both parens
			}
			else if(priority(pq.Peek(), next))//if it is time to empty some of the the operator queue into the postfix queue
			{
				while(!pq.IsEmpty() && priority(pq.Peek(), next))
					p.Enqueue(pq.Dequeue());
				next_char(pq, next);
			}
			else
			{
				next_char(pq, next);
			};
		}
	}

	//Empty the rest of the operators into the postfix queue
	while(!pq.IsEmpty())
		p.Enqueue(pq.Dequeue());
	q = p;
}

double solution(Queue<char>& q)//solves the equation and returns a floating point answer
{
	double a;
	double b;
	Stack<double> stack;

	while(!q.IsEmpty())
	{
		char next = q.Dequeue();
		if(((next - '0') >= 0) && ((next - '0') <= 9))//filter out all non-arithmetic characters
			stack.Push((next - '0'));
		else if(next == '+')//perform operator +
		{
			a = stack.Pop();
			b = stack.Pop();
			b += a;
			stack.Push(b);
		}
		else if(next == '-')//perform operator -
		{
			a = stack.Pop();
			b = stack.Pop();
			b -= a;
			stack.Push(b);
		}
		else if(next == '*')//perform * operator
		{
			a = stack.Pop();
			b = stack.Pop();
			b *= a;
			stack.Push(b);
		}
		else if(next == '/')//perform / operator
		{
			a = stack.Pop();
			b = stack.Pop();
			b /= a;
			stack.Push(b);
		}
		else//perform ^ operation
		{
			a = stack.Pop();
			b = stack.Pop();
			stack.Push(pow(b, a));
		}
	}//end while, q is empty, stack.num_items == 1

	return stack.Pop();//return the final value pushed onto the stack

}

void next_char(Queue<char>& pq, char next)
{
	Queue<char> temp;
	while(!pq.IsEmpty() && priority(pq.Peek(), next) && (next != '('))//Sift through everything with priority over next, add an open paren immediately
		temp.Enqueue(pq.Dequeue());
	temp.Enqueue(next);//insert next
	while(!pq.IsEmpty())//finish copying the Queue
		temp.Enqueue(pq.Dequeue());
	pq = temp;//set pq equal to the new queue
}

bool notop(char c)
{
	return ((c != '+') && (c != '-') && (c != '*') && (c != '/') && (c != '^') && (c != '(') && (c != ')'));
}

bool priority(char a, char b)
{
	if((b == '+') || (b == '-'))
		return ((a != '(') && (a != ')'));//a will always have priority if b is + or - unless a is a parenthesis, for our purposes
	else if((b == '*') || (b == '/'))
		return ((a == '^') || (a == '*') || (a == '/'));// * and / have equal priority
	else
		return false;
}
