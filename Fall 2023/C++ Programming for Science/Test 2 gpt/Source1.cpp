#include <iostream>
#include <string>
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
    string inputCode;
    cout << "Enter a 27-digit barcode: ";
    cin >> inputCode;


    string postalCode = processCode(inputCode);
    postalCode = postalCode.substr(0, 5);
    cout << "Zip code: " << postalCode << endl;

    return 0;
}
