/*
 *Convert a set of 1's and 0's to their integer form
 */
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	char input[8];
	while(cin.get(input, 9))
	{
		int out = 0;
		for(int i = 0; i < 8; i++)
			if(input[i] == '1')
				out += pow(2, (7-i));
		cout << out << " ";
	}
	cout << endl;
	return 0;
}
