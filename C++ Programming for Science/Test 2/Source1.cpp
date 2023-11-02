#include <iostream>
#include <string>
#include <random>
using namespace std;


// Function to decode a group of five digits into a zip code digit
int decode(char group[]) {
    int values[] = { 7, 4, 2, 1, 0 }; // values for each digit
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += (group[i] - '0') * values[i]; // multiply value with digit and add to sum
    }
    if (sum == 11) { // special case for zero
        return 0;
    }
    else {
        return sum;
    }
}


// Function to decode the entire bar code
string decodeBarCode(string barcode) {
    string zipCode = "";
    char group[6] = ""; // array to store each group of five digits (plus null terminator)
    int groupIndex = 0;
    for (int i = 1; i < 26; i++) { // iterate over all digits in the barcode
        group[groupIndex++] = barcode[i];
        if (groupIndex == 5) { // if we've read 5 digits, decode the group and add the resulting digit to the zip code
            group[groupIndex] = '\0'; // null terminate the group string
            int digit = decode(group); // decode the group
            zipCode += to_string(digit); // add digit to zip code
            groupIndex = 0; // reset the group index
        }
    }
    return zipCode;
}


int main() {
    // Generate a random barcode of 27 series of 1's or 0's
    char barcode[28] = "1"; // first digit is always 1
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);
    for (int i = 1; i < 26; i++) {
        barcode[i] = dist(gen) + '0';
    }
    barcode[26] = '1'; // last digit is always 1
    barcode[27] = '\0'; // null terminate the barcode string


    cout << "Generated barcode: " << barcode << endl;


    // Decode the barcode into a zip code
    string zipCode = decodeBarCode(barcode);
    zipCode = zipCode.substr(0, 5); // take only the first 5 digits
    cout << "Zip code: " << zipCode << endl;


    return 0;
}