/*
 *Convert a set of 1's and 0's to their char form
 *Only print them if they are printable
 */
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	char input[8];
	while(cin.get(input, 9))
	{
		int sum = 0;
		for(int i = 0; i < 8; i++)
			if(input[i] == '1')
				sum += pow(2, (7-i));
		if(sum >= 32 && sum <= 122)
		{
			char out = sum;
			cout << out;
		}	
	}
	cout << endl;
	return 0;
}

