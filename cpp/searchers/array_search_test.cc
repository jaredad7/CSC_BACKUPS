#include <iostream>
#include "array_search.h"
#include "array_search.h"

using namespace std;

int main()
{
	int int_array[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++)
		int_array[i] = (i*i);//int_array[i] = i^2

	float float_array[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++)
		float_array[i] = (i/2);//float_array[i] = i/2

	cout << "bin search of ints for 3 yeilds: " << bin_search(int_array, 3) << endl;
	cout << "bin search of ints for 256 yeilds: " << bin_search(int_array, 256) << endl;
	cout << "seq search of ints for 3 yeilds: " << seq_search(int_array, 3) << endl;
	cout << "seq search of ints for 256 yeilds: " << seq_search(int_array, 256) << endl;

	cout << "bin search of floats for 3.25 yeilds: " << bin_search(float_array, (float)3.25) << endl;
	cout << "bin search of floats for 10 yeilds: " << bin_search(float_array, (float)10.5) << endl;
	cout << "seq search of floats for 3.25 yeilds: " << seq_search(float_array, (float)3.25) << endl;
	cout << "seq search of floats for 10 yeilds: " << seq_search(float_array, (float)10.5) << endl;


	return 0;
}
