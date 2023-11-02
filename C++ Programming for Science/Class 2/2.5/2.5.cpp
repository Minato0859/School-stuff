#include <iostream>
using namespace std;

int main()
{
	int sec;
	double dist;

	cout << "Input time in seconds: ";
	cin >> sec;
	
	dist = (9.8 / 2) * sec * sec;

	cout << "Total distance in freefall: " << dist << endl;
	return 0;

}