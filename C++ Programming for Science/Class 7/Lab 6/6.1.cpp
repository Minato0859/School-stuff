#include <iostream>
using namespace std;

int main()
{
    int count = 1; // initialize count

    while (count <= 10) // loop 10 times
    {
        // output line of text
        cout << (count % 2 ? "****" : "++++++++") << endl;
        ++count; // increment count
    } // end while
} // end main