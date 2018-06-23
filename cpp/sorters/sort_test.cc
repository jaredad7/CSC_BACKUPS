#include <iostream>
#include <cstdlib>
#include "sorters.h"

using namespace std;

int main()
{
	int seed;
	cout << "Seed: ";
	cin >> seed;
	cout << endl;

	srand(seed);

	int array[MAX_SORT_SIZE];
	for(int i = 0; i < MAX_SORT_SIZE; i++)
		array[i] = abs((rand() % 3000));

	bubble_sort(array);

	for(int i = 0; i < MAX_SORT_SIZE; i++)
		cout << array[i]  << " ";

	return 0;
}
