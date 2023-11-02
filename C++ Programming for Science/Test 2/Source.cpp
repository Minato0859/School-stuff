#include <iostream>
#include "barcode.h"
using namespace std;

int main()
{
	const int array_size = 5, arraysize = 25;
	long double num;
	int array1[array_size], array2[array_size], array3[array_size], array4[array_size], array5[array_size];

	barcode postnet;

	void intoarray(int num, int* array1, int* array2, int* array3, int* array4, int* array5, int arraysize);

	void displayarray(int num, int* array1, int* array2, int* array3, int* array4, int* array5, int arraysize);

}





//// Function that returns a pointer to an array
//int* createArray() {
//    int* myArray = new int[5];  // Dynamically allocate an array
//    myArray[0] = 1;
//    myArray[1] = 2;
//    myArray[2] = 3;
//    myArray[3] = 4;
//    myArray[4] = 5;
//    return myArray;
//}
//
//int main() {
//    int* result = createArray();
//    for (int i = 0; i < 5; i++) {
//        std::cout << result[i] << " ";
//    }
//    delete[] result;  // Don't forget to deallocate the memory
//    return 0;
//}
