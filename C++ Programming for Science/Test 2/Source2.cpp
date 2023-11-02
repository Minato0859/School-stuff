#include <iostream>
#include <string>
#include <random>
using namespace std;

int translate(char seq[]) {
    int weights[] = { 7, 4, 2, 1, 0 };
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += (seq[i] - '0') * weights[i];
    }
    if (total == 11) {
        return 0;
    }
    else {
        return total;
    }
}

string processCode(string inputCode) {
    string postalCode = "";
    char subGroup[6] = "";
    int subIndex = 0;
    for (int i = 1; i < 26; i++) {
        subGroup[subIndex++] = inputCode[i];
        if (subIndex == 5) {
            subGroup[subIndex] = '\0';
            int number = translate(subGroup);
            postalCode += to_string(number);
            subIndex = 0;
        }
    }
    return postalCode;
}

int main() {
    char inputCode[28] = "1";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, 1);
    for (int i = 1; i < 26; i++) {
        inputCode[i] = distribution(generator) + '0';
    }
    inputCode[26] = '1';
    inputCode[27] = '\0';

    cout << "Generated barcode: " << inputCode << endl;

    string postalCode = processCode(inputCode);
    postalCode = postalCode.substr(0, 5);
    cout << "Zip code: " << postalCode << endl;

    return 0;
}
