
// C++ program to illustrate
// atexit() function when it throws an exception.
#include <bits/stdc++.h>
using namespace std;

void shows_Exception()
{
	int y = 50, z = 0;
	// Program will terminate here
	int x = y / z;

	// Cannot get printed as the program
	// has terminated
	cout << "Divided by zero";
}
// Driver Code
int main()
{
	int value;
	value = atexit(shows_Exception);
	if (value != 0) {
		cout << "atexit() function registration failed";
		exit(1);
	}

	// Executed at the starting
	cout << "Registration successful" << endl;
	return 0;
}
