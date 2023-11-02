#include <iostream>
using namespace std;

int main()
{
	int mill_gram, cups;

	cout << "Please input the amount of milligrams of coffee: ";
	cin >> mill_gram;
	
	cups = (10000 / mill_gram); //(10000 % mill_gram) ;   we need an if statement

	cout << "It would take " << cups << " cups " << "to kill you" << endl;

	return 0;
}