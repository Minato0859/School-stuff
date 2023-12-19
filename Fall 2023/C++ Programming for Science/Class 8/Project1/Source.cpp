#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double pi;
	pi = 4;
	int i, k;
	for (i = 1, k = 1; i <= 1000; i++)
	{
		k = 2 * i + 1;
		pi += ((pow(-1, i) * 4) / k);
		cout << i << " " << pi << endl;
	}

	
	return 0;
}