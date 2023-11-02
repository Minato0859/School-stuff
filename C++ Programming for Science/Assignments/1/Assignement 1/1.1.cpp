#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int in, num1, num2, num3, num4, num5;

	cout << "Input a 5 digit number: ";
	cin >> in;

	num1 = in / 10000;
	num2 = in / 1000 % 10;
	num3 = in / 100 % 10;
	num4 = in / 10 % 10;
	num5 = in % 10;

	cout << left << setw(4) << num1 << setw(4) << num2 << setw(4) << num3 << setw(4) << num4 << setw(4) << num5 << endl;

	return 0;
}
