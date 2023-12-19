#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int N;
    double Nfactorial, etox, x;

    cout << "Enter a positive integer for level of accuracy: ";
    cin >> N;

    cout << "Enter x value: ";
    cin >> x;

    Nfactorial = 1;
    etox = 1;

    for (int i = 0; i <= N - 1; ++i)
    {
        Nfactorial = Nfactorial * (i + 1);

        etox += pow(x,i+1) / Nfactorial;

    }
    cout << "e^x =  " << etox << endl;
    return 0;
}
