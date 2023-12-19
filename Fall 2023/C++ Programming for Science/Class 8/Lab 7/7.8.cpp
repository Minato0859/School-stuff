//8. Calculate the value of pi from the infinite series :
//pi = 4 - 4 / 3 + 4 / 5 - 4 / 7 + 4 / 9 - 4 / 11 + ... with a given accuracy.


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double pi;
	pi = 4;
	for (int i = 1, int k = 1; i <= 100; k = 2 * i + 1 , i++)
		pi += (pow(-1, i) * 4) / k;

	cout << pi << endl;
	return 0;
}
