#include <iostream>
#include <cstdlib>

using namespace std;

void solve(int n, string t1, string t2, string t3);

int main(int argc, char** argv)
{
	int discs = 0;
	if(argc <= 1)
	{
		cout << "Please input a number of discs: ";
		cin >> discs;
	}
	else if(argc == 2)
	{
		discs = atoi(argv[1]);
	}
	else
	{
		cout << "Too many arguments." << endl;
		cout << "Please pass only one argument" << endl;
	}
	solve(discs, "Source", "Spare", "Destination");

	return 0;
}

void solve(int n, string t1, string t2, string t3)
{
	if(n > 0)
	{
		solve(n-1, t1, t3, t2);
		cout << n << " disc to " << t3 << " peg" << endl;
		solve(n-1, t2, t1, t3);
	}
}