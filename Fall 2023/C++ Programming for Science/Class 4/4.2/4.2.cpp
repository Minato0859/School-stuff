#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3, big, small;
	double sum, average, product;

	cout << "Input 3 numbers: ";
	cin >> num1 >> num2 >> num3;

	big = num1;
	small = num2;
	if (num2 > num1)
		big = num2;
	if (num3 > num2)
		big = num3;
	if (num3 < num2)
		small = num3;
	if (num1 < num3)
		small = num1;

	sum = num1 + num2 + num3;
	average = sum / 3.0;
	product = num1 * num2 * num3;

	cout << "Sum is " << sum << "\nAverage is " << average << "\nProduct is " << product << "\nSmallest is " << small << "\nLargest is " << big << endl;
	 
	return 0;
}
