#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void solve(int n, string t1, string t2, string t3, vector<string> &result);

int main()
{
	cout << "Please input a number of discs: ";
	int discs;
	cin >> discs;
	vector<string> result;
	solve(discs, "Source", "Spare", "Destination", result);
}

void solve(int n, string t1, string t2, string t3, vector<string> &result)
{
	if(n > 0)
	{
		solve(n-1, t1, t3, t2, result);
		result.push_back(n + " disc to " + t3 + " peg");
		solve(n-1, t2, t1, t3, result);
	}
}
