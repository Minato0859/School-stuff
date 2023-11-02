#include <iostream>
using namespace std;

int main()
{
	double salary, rate = 16.78;
	int hours, over, under;

	cout << "Input hours worked";
	cin >> hours;

	if (hours > 40)
		salary = (hours - 40) * 16.78 * 1.5 + (40 * 16.78);
	else
		salary = hours * 16.78;

	cout << "\nThe salary is: " << salary << endl;

	return 0;


		
}