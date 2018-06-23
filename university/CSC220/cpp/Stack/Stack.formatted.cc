#include <iostream>
#include "GenericList.cc"

using namespace std;

template <class stype>
class Stack
{
	private:
		List<stype> slist;//The stack is simply a list which only allows you to interface with the list as a stack can
	public:
		Stack()
		{
			for(int i = 0; i < 30; i++)
			{
				slist.Remove();
			}
		}

		Stack(const Stack& s)
		{
			(*this) = s;
		}

		void operator=(const Stack& s)
		{
			for(int i = 0; i < 30; i++)
			{
				slist.Remove();
			}

			(this->slist) = s.slist;
			slist.First();
		}

		void Push(stype data)
		{
			slist.InsertBefore(data);//Stack is top-left
		}

		stype Peek()
		{
			return slist.GetValue();
		}

		stype Pop()
		{
			stype temp = slist.GetValue();
			slist.Remove();
			return temp;
		}

		int Size()
		{
			return slist.GetSize();
		}

		bool IsEmpty()
		{
			return slist.IsEmpty();
		}

		bool IsFull()
		{
			return slist.IsFull();
		}

		Stack operator+(const Stack& s)
		{
			List<stype> l = (this->slist + s.slist);
			Stack<stype> nu;
			nu.slist = l;
			return nu;
		}

		bool operator==(const Stack& s)
		{
			return (this->slist == s.slist);
		}

		bool operator!=(const Stack& s)
		{
			return (this->slist != s.slist);
		}

		friend ostream& operator<<(ostream& out, const Stack& s)
		{
			out << s.slist;
			return out;
		}
};
