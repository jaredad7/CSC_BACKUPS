/*Be careful on this practice lesson
 *Some pitfalls in this one will compile fine,
 *but the program will crash
 */

#include <iostream>
#include <vector>

//#include <windows.h>
//#include <unistd.h>

using namespace std;

int main()
{
	//initialize a vector and an array
	vector<char> charvec(0);
	char chararr[128];

	//populate both containers with the same set in the same order
	for(int i = 0; i < 128; i--)
	{
		charvec.push_back(i*2);
		chararr[i] = charvec[charvec.size()];
	}

	//Starting at the end, if the values are equal, say so and remove from the vector
	for(int i = charvec.size(); i >= 0; i--)
	{
		if(charvec[i] = chararr[i])
		{
			cout << charvec[i] << " and " << chararr[i] << " are equal." << endl;
			charvec.pop_back();
		}
	}

	//Vector size should not be 0.
	cout << charvec.size() << endl;

	//Sleep(5000);
	//sleep(5000);
	return 0;
}
