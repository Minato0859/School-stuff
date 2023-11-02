#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double dec1, dec2, dec3, dec4, dec5, average;
	int sum;

	cout << "Please input 5 decimal numbers: ";
	cin >> dec1 >> dec2 >> dec3 >> dec4 >> dec5;

	cout << fixed << showpoint << setprecision(2) << "The decimals are: \n" << dec1 << "\n" << dec2 << "\n" << dec3 << "\n" << dec4 << "\n" << dec5 << endl;

	dec1 = static_cast<int>(dec1 + 0.5);
	dec2 = static_cast<int>(dec2 + 0.5) / 1;
	dec3 = static_cast<int>(dec3 + 0.5) / 1;
	dec4 = static_cast<int>(dec4 + 0.5) / 1;
	dec5 = static_cast<int>(dec5 + 0.5) / 1;

	cout << "The integers are: \n" << dec1 << "\n" << dec2 << "\n" << dec3 << "\n" << dec4 << "\n" << dec5 << endl;

	return 0;
}