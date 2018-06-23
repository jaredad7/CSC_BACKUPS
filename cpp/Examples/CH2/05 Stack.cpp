#include "03 Linked List.cpp"

using namespace std;

/*
 *This chapter is more a study of a certain kind of data structure.
 *This data structure is called a stack. Imagine a stack of dishes.
 *You can place more dishes on top of the stack, and you can always
 *take the top dish off, but if you try to remove a different dish,
 *the whole thing will come crashing down.
 *
 *A stack data structure is like this. We call the addition of a 
 *piece of data a "push" and the removal a "pop." We can only "pop"
 *the top piece of data, and any data we "push" becomes the top.
 */

//Again, we want to store any kind of data in our Stack
template <class stype>
class Stack
{
private:
	//Our stack will use a linked list as its backend.
	LinkedList<stype> ll;
public:
	//The push method should simply add a piece of data
	void push(stype data)
	{
		ll.add(data);
		ll.setCurrent(ll.size()-1);
	}

	//The pop method should remove data from the list and return the removed data
	stype pop()
	{
		stype data = NULL;
		if(ll.size() > 0)
		{
			data = ll.getCurrent();
			ll.remove();
		}
		return data;
	}

	//See the size of our stack
	int size()
	{
		return ll.size();
	}
};