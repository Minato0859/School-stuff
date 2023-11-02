#include <iostream>
using namespace std;

int main()

{
	char redo = 'Y';
	while (redo == 'Y')
	{
		int choice;

		cout << "\n(1)Pounds to Kilograms\n(2)Kilograms to pounds\nSelection #: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			double kilos, pounds;

			cout << "\nEnter amount of pounds: ";
			cin >> pounds;

			kilos = pounds / 2.2;

			cout << pounds << " pounds is " << kilos << " kilograms\nwould you like to run the program again(Y/N):";
			cin >> redo;
			break;


		}
		case 2:
		{
			double kilos, pounds;

			cout << "\nEnter amount of kilograms: ";
			cin >> kilos;

			pounds = kilos * 2.2;

			cout << kilos << " kilograms is " << pounds << " pounds\nwould you like to run the program again(Y/N):";
			cin >> redo;
			break;

		}
		return 0;

		}
	}
}

	