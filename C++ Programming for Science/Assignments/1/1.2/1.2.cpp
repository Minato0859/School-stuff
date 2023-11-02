#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    int i;


    for (int i = 0; i <= 10; ++i)
    {
        cout << left << setw(5) << i << setw(5) << i * i << setw(5) << i * i * i << endl;
    }
       
   return 0;
}