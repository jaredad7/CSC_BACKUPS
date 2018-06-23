/****************************************************
 * <Jared Dembrun>
 * <9/20/2013>
 * <EasyList>
 *
 * <A wrapper object for an array which makes the use of an array easier;
 *  similar to an array list in java>
 ****************************************************/

#include <iostream>
#include <sstream>
using namespace std;

const int MAX_SIZE = 30;

class List
{
	private:
		int end;
		int curr;
		int list[MAX_SIZE];

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
             end = -1;
             curr = end;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
             *this = l;
        }
        
		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
             end = l.end;
              
             if(IsEmpty())
                 curr = l.curr;
             else
             {
                 for(curr = 0; curr <= end; curr++)
                     list[curr] = l.list[curr];
                 curr--;//go back to actual index, must pass index to escape loop
             }
		}

		// navigates to the beginning of the list
		// this should not be possible for an empty list
		void First()
		{
             if(!IsEmpty())
                 curr = 0;
		}

		// navigates to the end of the list
		// the end of the list does not necessarily correspond to its maximum size; it's just at the last existing element
		void Last()
		{
             curr = end;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
             if(!IsEmpty())
             {
                 if(pos <= end)
                     curr = pos;
             }
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
             if(!IsEmpty() && curr > 0)
                 curr--;
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
             if(!IsEmpty() && curr < end)
                 curr++;
		}

		// returns the location of the current element (or -1)
		int GetPos() const
		{
            return curr;
		}

		// returns the value of the current element (or -1)
		int GetValue() const
		{
            if(!IsEmpty())
                return list[curr];
            
            return -1;
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize() const
		{
            return end+1;
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(int data)
		{
             if(!IsFull() && !IsEmpty())
                 for(int i = end+1; i >= curr; i--)
                 {
                     if(i != curr)
                     {
                         list[i] = list[i-1];
                     }
                     else
                     {
                         list[i] = data;
                     }
                 }
             else if(IsEmpty())
             {
                  list[end+1] = data;
                  curr = 0;
             }
             if(end < 29)
                 end++;
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(int data)
		{
             if(!IsFull())
             {
                 curr++;
                 InsertBefore(data);
             }
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
             if(!IsEmpty())
             {
                 int temp_curr = curr;
                 for(temp_curr; temp_curr <= end; temp_curr++)
                 {
                     list[temp_curr] = list[(temp_curr+1)];
                 }
                 end--;
                 
                 if(curr > end)
                     curr = end;
             }
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(int data)
		{
             if(!IsEmpty())
                 list[curr] = data;
		}

		// returns if the list is empty
		bool IsEmpty() const
		{
             return (end == -1);
		}

		// returns if the list is full
		bool IsFull() const
		{
             return (end == 29);
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
             List new_list = *this;
             
             new_list.curr = 0;
             for(new_list.end = new_list.GetSize(); ((new_list.end < MAX_SIZE) && (curr < l.GetSize())); new_list.end++,new_list.curr++)
             {
                 if(l.IsEmpty())
                     break;
                 new_list.list[new_list.end] = l.list[new_list.curr];
                 if(new_list.end == (MAX_SIZE-1))
                     break;
             }
             
             new_list.curr = new_list.end;
             return new_list;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
             //empty lists are equal by value
             //assumes at beginning lists are unequal
             bool isEqual = false;
             if(l.IsEmpty() && IsEmpty())
                 isEqual = true;
             else if(l.end == end)
             {
                 isEqual = true;
                 for(int i = 0; i <= end; i++)
                     if(l.list[i] != list[i])
                         isEqual = false;
             }
             
             return isEqual;
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
             return !(*this == l);
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
               if(l.IsEmpty())
                   out << "NULL";
               else
		   //ostringstream oss("");
                   for(int i = 0; i <= l.end; i++)
                       oss << l.list[i] << " ";
               //out << oss.str();     
               return out;
		}
};
