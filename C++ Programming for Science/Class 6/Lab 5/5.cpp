#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "Select your input type:\n(1)Feet and inches\n(2)Inches\nSelection #: ";
	cin >> choice;

	switch (choice)
	{
	case 1 : 
	{
		int feet_dad, inch_dad, feet_mom, inch_mom, height_dad, height_mom;
		cout << "\nEnter fathers height in feet, seperate by a space: ";
		cin >> feet_dad >> inch_dad;
		height_dad = inch_dad + (feet_dad * 12);
		cout << "Enter mothers height in feet, seperate by a space: ";
		cin >> feet_mom >> inch_mom;
		height_mom = inch_mom + (feet_mom * 12);

		double Hmale, Hfemale;
		Hmale = ((height_mom * 13 / 12.0) + height_dad) / 2;
		Hfemale = ((height_dad * 12 / 13.0) + height_mom) / 2;

		char gender;
		cout << "\nIs your child male(m) or female(f)\nSelection: " ;
		cin >> gender;

		switch (gender)
		{
		case 'm':
		{
			int choice;

			cout << "\nSelect your output type:\n(1)Feet and inches\n(2)Inches\nSelection #:  " ;
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				int mfeet, minches;

				mfeet = Hmale / 12;
				minches = static_cast<int>(Hmale) % 12;

				cout << "\nThe male child's height is : " << mfeet << " feet " << minches << " inches" << endl;
				break;
			}
			case 2:
				cout << "\nThe male child's hieght is: " << Hmale << " inches" << endl;
				break;
			}
			break;
		}
		case 'f':
		{
			int choice;

			cout << "\nSelect your output type:\n(1)Feet and inches\n(2)Inches\nSelection #:  " ;
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				int ffeet, finches;

				ffeet = Hfemale / 12;
				finches = static_cast<int>(Hfemale) % 12;

				cout << "\nThe female child's height is : " << ffeet << " feet " << finches << " inches" << endl;
				break;
			}
			case 2:
				cout << "\nThe female child's hieght is: " << Hfemale << " inches" << endl;
				break;
			}
		}


		}break;

	}
	case 2 : 
	{
		int inch_dad, inch_mom, height_dad, height_mom;
		cout << "\nEnter fathers height in inches: ";
		cin >> inch_dad;
		height_dad = inch_dad;
		cout << "Enter mothers height in inches: ";
		cin >> inch_mom;
		height_mom = inch_mom;

		double Hmale, Hfemale;
		Hmale = ((height_mom * 13 / 12.0) + height_dad) / 2;
		Hfemale = ((height_dad * 12 / 13.0) + height_mom) / 2;

		char gender;
		cout << "\nIs your child male(m) or female(f)\nSelection :  ";
		cin >> gender;

		switch (gender)
		{
		case 'm':
		{
			int choice;

			cout << "\nSelect your output type:\n(1)Feet and inches\n(2)Inches\nSelection #:  " ;
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				int mfeet, minches;

				mfeet = Hmale / 12;
				minches = static_cast<int>(Hmale) % 12;

				cout << "\nThe male child's height is : " << mfeet << " feet " << minches << " inches" << endl;
				break;
			}
			case 2:
				cout << "\nThe male child's hieght is: " << Hmale << " inches" << endl;
				break;
			}
		}break;
		case 'f':
		{
			int choice;

			cout << "\nSelect your output type:\n(1)Feet and inches\n(2)Inches\nSelection #:  " ;
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				int ffeet, finches;

				ffeet = Hfemale / 12;
				finches = static_cast<int>(Hfemale) % 12;

				cout << "\nThe female child's height is : " << ffeet << " feet " << finches << " inches" << endl;
				break;
			}
			case 2:
				cout << "\nThe female child's hieght is: " << Hfemale << " inches" << endl;
				break;
			}
		}break;


		}
	}
	}
	return 0;
	
}