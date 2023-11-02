#include <iostream>
using namespace std;

int main()
{
	int num1, num2;

	cout << "Input 2 numbers: ";
	cin >> num1 >> num2;

	if (num1 > num2)
		cout << num1 << " is larger";
	if (num2 > num1)
		cout << num2 << " is larger";
	else
		cout << "These numbers are equal";




}
