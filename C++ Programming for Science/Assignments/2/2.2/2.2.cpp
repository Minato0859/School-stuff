#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int N;
    double Nfactorial, e;

    cout << "Enter a positive integer for level of accuracy: ";
    cin >> N;

    Nfactorial = 1;
    e = 1;

    for (int i = 0 ; i <= N - 1; ++i)
    {
        Nfactorial = Nfactorial * (i + 1);

        e += 1 / Nfactorial;

    }
    cout << "e =  " << e << endl;
    return 0;
}
