#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double remaining, income, postincome, tax, clothes, supplies, bonds, parent_bonds, rate, hours;

	cout << "PLease input your hourly rate: ";
	cin >> rate;

	cout << "Number of hours worked: ";
	cin >> hours;
	

	income = hours * rate;
	remaining = income;
	tax = income * 0.14;
	postincome = income - tax;

	remaining -= tax;
	clothes = remaining * 0.1;
	supplies = remaining * 0.01;
	remaining -= (supplies + clothes);

	bonds = remaining * 0.25;
	parent_bonds = bonds / 2;

	cout << setprecision(2) << fixed;
	cout << setw(30) << left << "Pretax income:" << setw(15) << income << setw(30) << "\nPost tax income: " << setw(15) << postincome << setw(30) << "\nClothes and accessories: " << setw(15) << clothes << setw(30) << "\nSchool Supplies: "
		<< setw(15) << supplies << setw(30) << "\nSavings bonds: " << setw(15) << bonds << setw(30) << "\nAdditional savings bonds: " << setw(15) << parent_bonds << endl;

	return 0;
}

