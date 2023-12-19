#include <iostream>
using namespace std;

int main()
{
	double length_cm, length_inch;
	int yard, feet, inch;

	cout << "Please input a lenght in centimeters: ";
	cin >> length_cm;

	length_inch = length_cm / 2.54;
	yard = static_cast<int>(length_inch / 36);
	feet = static_cast<int>((length_inch - (yard * 36)) / 12);
	inch = static_cast<int>((length_inch - ((feet * 12) + (yard * 36))));

	cout << yard << " yard(s), " << feet << " feet (foot), " << inch << " inch(es). " << endl;

	return 0;

}


