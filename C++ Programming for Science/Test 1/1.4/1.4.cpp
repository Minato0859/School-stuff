#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    int i, N;
    double Nfactorial;

    

    Nfactorial = 1;

    for (int i = 1; i <= 100; ++i)
    {
        cout << i << "\t" << Nfactorial << endl;
        Nfactorial = Nfactorial * (i + 1);

    }
    
    return 0;
}
