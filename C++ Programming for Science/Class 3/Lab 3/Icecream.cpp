#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double price_single, price_double, price_triple, costsingle, costdouble, costtriple, costtotal;
	price_single = 1.49;
	price_double = 2.49;
	price_triple = 3.49;

	int num_single, num_double, num_triple, num_total;


	cout << "Number of single scoop cones sold: ";
	cin >> num_single;

	cout << "\nNumber of double scoop cones sold: ";
	cin >> num_double;

	cout << "\nNumber of triple scoop cones sold: ";
	cin >> num_triple;

	num_total = num_single + num_double + num_triple;
	costsingle = (num_single * price_single);
	costdouble = (num_double * price_double);
	costtriple = (num_triple * price_triple);
	costtotal = costsingle + costdouble + costtriple;

	cout << setprecision(2) << fixed;

	cout << left << setw(25) << "\nDeLIGHTful cones: " << setw(25) << num_single << "$" << costsingle << endl;

	cout << left << setw(25) << "\nDouble DeLIGHT cones: " << setw(25) << num_double <<  "$" << costdouble << endl;

	cout << left << setw(25) << "\nTriple DeLIGHT cones: " << setw(25) << num_triple <<  "$" << costtriple << endl;

	cout << left << setw(25) << "\nTotal:" << setw(25) << num_total << "$" << costtotal << endl;

	return 0;



}