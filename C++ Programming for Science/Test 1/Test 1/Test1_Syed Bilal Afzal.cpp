#include <iostream>
using namespace std;

int main()

{
	int firstNum, secondNum, sum;

	cout << "Enter 2 integers in increasing order seperated by a space:  " << endl;
	cin >> firstNum >> secondNum;

	sum = 0;

	for (; firstNum <= secondNum; firstNum++)
	{
		if (firstNum % 2 == 0)
		{
			sum = sum + firstNum;
		}

	} cout << "sum of all even number inbetween " << "is: " << sum;

	return 0;
}