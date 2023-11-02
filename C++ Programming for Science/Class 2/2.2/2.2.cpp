#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double principal, rate, final_amount;
	int years;

	cout << "Please input your initial investment: ";
	cin >> principal;

	cout << "Please input your the time in years: ";
	cin >> years;

	cout << "Please input your yearly interest rate: ";
	cin >> rate;

	final_amount = principal * pow((1 + rate), years);

	cout << "Your final amount is : " << final_amount << endl;

	return 0;





}