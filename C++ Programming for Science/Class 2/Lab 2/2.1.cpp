#include <iostream>
using namespace std;

int main()
{
	int time, hours, minutes, seconds;

	cout << "Please enter a time in seconds: ";
	cin >> time;

	hours = time / 3600;
	minutes = time / 60;
	seconds = time % 3600;

	cout << hours << " hours " << minutes << " minutes " << seconds << " seconds " << endl;

	return 0;

}

