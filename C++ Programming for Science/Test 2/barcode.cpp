#include <iostream>
#include <cmath>
#include "barcode.h"

using namespace std;

long double num;

barcode::barcode()
{
	cout << "Enter the 25 digit pin: ";
	cin >> num;

};

void barcode::intoarray(int num, int* array1, int* array2, int* array3, int* array4, int* array5, int arraysize)
{
	for (int i = 25; i >= 0; i--) //put input into an array
	{
		

		if (i > 20)
		{
			array1[25 - i] = (num / (static_cast<int>(pow(10, i)))) % 10;
		}

		else if (i > 15)
		{
			array2[20 - i] = (num / (static_cast<int>(pow(10, i)))) % 10;
		}

		else if (i > 10)
		{
			array3[15 - i] = (num / (static_cast<int>(pow(10, i)))) % 10;
		}

		else if (i > 5)
		{
			array4[10 - i] = (num / (static_cast<int>(pow(10, i)))) % 10;
		}

		else if (i > 0)
		{
			array5[5 - i] = (num / (static_cast<int>(pow(10, i)))) % 10;
		}


	}

	void displayarray(int num, int* array1, int* array2, int* array3, int* array4, int* array5, int arraysize);
	{
		for (int val : array1)
			cout << val;
		for (int val : array2)
			cout << val;
		for (int val : array3)
			cout << val;
		for (int val : array4)
			cout << val;
		for (int val : array5)
			cout << val;
	};

}

