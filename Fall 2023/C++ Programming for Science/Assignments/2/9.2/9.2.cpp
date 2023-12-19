#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string input;
    int num;
    cout << "Enter numbers you wish to round seperated by a space: ";
    getline(cin, input); // read the input line from the user

    stringstream ss(input); // create a stringstream object from the input

    int count = 0;
    while (ss >> num) {
        count++; // count the number of integers in the input
    }

    int* arr = new int[count]; // dynamically allocate an array to store the integers

    ss.clear(); // clear the stringstream flags
    ss.seekg(0, ios::beg); // reset the stringstream position to the beginning

    int i = 0;
    while (ss >> num) {
        arr[i] = num; // store each integer in the array
        i++;
    }

    // use the array here

    delete[] arr; // free the dynamically allocated memory
    return 0;
}
