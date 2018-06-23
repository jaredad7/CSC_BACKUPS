#include <iostream>

using namespace std;

/*
 *It's great to have arrays, but what if we want a set of
 *data with a dynamic size? Of course, we already have the vector
 *class, but someone had to write that. In the next few lessons, we
 *will explore the concept of a Linked List, which is a commonly used data structure.
 *
 *A Linked List is an object which contains nodes, which are containers
 *for data which also have a pointer to another node. The list will keep track
 *of the head node, the tail node, and the node to which it currently points.
 *It will also keep track of the number of nodes it contains.
 *
 *This is a great time to explore another concept. This Linked List file
 *will not be compiled into an executable file. Instead, we will make it
 *an external library and refer to it in lesson 4, which is just a test
 *file. We will see how to reference an external library in lesson 4.
 *
 *Lesson 3 is very intense and covers a lot of new concepts, so take
 *your time. It would probably be best to spend more time on it than
 *you would usually spend.
 */

//We will make the LinkedList able to store any type of data.
template <class ltype>
class LinkedList
{
private:
	//Our node definition
	struct Node
	{
		ltype data;
		Node *next;
	};

	//Three node pointers used to create the list
	Node *head;
	Node *tail;
	Node *current;

	//A counter to track the number of nodes in the class.
	int counter;

public:
	//We only want to create nodes with functions designed to add them.
	LinkedList()
	{
		counter = 0;
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	
	//Creates a new tail node and adds datatype d to it.
	void add(ltype d)
	{
		if(counter > 0)
		{
			Node *n = new Node;

			/*
			 *If you recall from previous lessons, whenever we access a member
			 *of an object or a struct, we use a dot. For example, we would say
			 *object.getName();
			 *
			 *Because n is a pointer to an object, however, and not the object itself,
			 *we use the symbol ->
			 *This lets the compiler know that it needs to dereference the pointer and then
			 *treat the dereferenced object as though we were using a dot on it.
			 */
			n->data = d;
			tail->next = n;
			tail = n;
		}
		else
		{
			head = new Node;
			current = head;
			tail = head;
			current->data = d;
		}
		tail->next = NULL;
		counter++;
	}

	//Sets the current node to the first one that matches the passed data value
	//Return 0 if the value was found, -1 if not (set current to tail), -2 if empty
	int setCurrent(ltype d)
	{
		if(counter > 0)
		{
			current = head;
			while(current != NULL)
			{
				if(current->data == d)
				{
					return 0;//This return will immediately exit the function
				}
				else current = current->next;
			}
			
			current = tail;
			return -1;//The value was not found
		}

		return -2;//The list was empty.
	}

	//Sets current to the node indicated as long as it exists.
	void setCurrentPos(int n)
	{
		if(counter > n)
		{
			current = head;
			for(int i = 1; i < n; i++)
			{
				current = current->next;
			}
		}
	}

	//Returns the size of the list
	int size()
	{
		return counter;
	}

	//Sets the value of the data in the current node to the type passed in.
	//Returns 0 if successful, -1 if list is empty
	void set(ltype d)
	{
		if(counter > 0)
		{
			current->data = d;
			return 0;
		}
		
		return -1;
	}

	//Returns the value at the current location
	//Returns null if empty
	ltype getCurrent()
	{
		if(counter > 0)
		{
			return current->data;
		}
		//When we compile, we will get a warning because the ltype might be null.
		//This is ok. we will still get an executable.
		return NULL;
	}

	//Moves current to the next node and returns the data value
	//Returns null and does not move current if current == tail
	ltype next()
	{
		if(current == tail)
		{
			return NULL;
		}
		else
		{
			current = current->next;
			return current->data;
		}
	}

	//Removes the current node and sets current to the next node.
	//Does nothing if the list is empty
	void remove()
	{
		if(counter > 1)
		{
			if(current == head)
			{
				current = head->next;
				delete head;
				head = current;
			}
			else
			{
				//We are going to find the node just before current so we can set its next to current's next
				//and then delete current
				Node *n = head;
				while(n->next != current)
				{
					n = n->next;
				}
				n->next = current->next;

				//Current may equal tail. In this case, we need to move tail, too.
				if(current == tail)
				{
					tail = n;
				}

				delete current;
				current = n;				
			}
			counter--;
		}
		else if(counter == 1)
		{
			delete head;
			head = NULL;
			tail = NULL;
			current = NULL;
			counter = 0;
		}
	}

	//Prints out all of the data in a formatted way.
	//Will appear as a list.
	//Leaves current at its current position
	//Adds the string <current> after the data in the current node
	void print()
	{
		Node *n = head;
		cout << "[";
		for(int i = 0; i < counter; i++)
		{
			cout << n->data;
			if(n == current)
			{
				cout << "<current>";
			}

			if(n != tail)
			{
				cout << ", ";
			}
			n = n->next;
		}
		cout << "]" << endl;
	}
};
