#include <iostream>
using namespace std;

int main()
{
	double a, b, c, xpos, xneg, sqrts, azerox;

	cout << "Enter a, b and c seoerated by a space: ";
	cin >> a >> b >> c;

	sqrts = (b * b) - (4 * a * c);

	xpos = (-b + sqrts)/(2*a);
	xneg = (-b - sqrts) / (2 * a);
	azerox = (-c) / b;

	if ((sqrts >= 0) && (a != 0))
	{
		cout << "X1:  " << xpos << endl;
		cout << "X2:  " << xneg << endl;
	}
	else if (sqrts < 0)
		cout << "Cannot compute square root of a negative number" << endl;
	else if (a == 0)
	{
		if (b != 0)
			cout << "X1: " << azerox << endl;
		else
			cout << "error (b=0)" << endl;
	}

	return 0;



	
}