#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double F, C;
	cout << "Enter tempreture as celsius: ";
	cin >> C;

	F = ((( 9 / 5.0) * C) + 32);

	cout << "Temprature in Farenheight: " << F << " degrees " << endl;

	return 0;


}