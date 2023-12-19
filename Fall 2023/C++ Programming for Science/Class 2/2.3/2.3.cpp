#include <iostream>
using namespace std;

int main()
{
	int Hfeet, Hinch, weight, remainder_inch, Ideal;

	cout << "Please input you height in but seperat your Feet and inches by a space: ";
	cin >> Hfeet >> Hinch;

	remainder_inch = ((Hfeet % 5) * 12) + Hinch;
	Ideal = (remainder_inch * 5) + 110;



	cout << "Your ideal bodyweight is: " << Ideal << endl;
	return 0;



	

	//cout << "Please input you weight in pounds: ";
	//cin >> weight;


}