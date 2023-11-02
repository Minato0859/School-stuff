#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    int i, N;
    double Nfactorial;

    cout << "Enter a positive integer: ";
    cin >> N;

    Nfactorial = 1;

    for (int i = 1; i <= N-1; ++i)
    {
        Nfactorial = Nfactorial * (i + 1);

        //cout << left << setw(5) << i << setw(5) << i * i << setw(5) << i * i * i << endl;
    }
    cout << "Factorial of " << N << " = " << Nfactorial << endl;
    return 0;
}
