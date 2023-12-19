#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 5;
const int MAX_VAL = 9;

void createRandom(int[]);
void getUserInput(int[]);
int countMatching(int[], int[]);

int main()
{
    int randomNumbers[SIZE];
    int userInput[SIZE];
    int matching;

    srand(time(0));
    createRandom(randomNumbers);
    getUserInput(userInput);
    matching = countMatching(randomNumbers, userInput);

    cout << "Random numbers: ";
    for (int i = 0; i < SIZE; i++)
        cout << randomNumbers[i] << " ";
    cout << endl;

    cout << "User input:     ";
    for (int i = 0; i < SIZE; i++)
        cout << userInput[i] << " ";
    cout << endl;

    cout << "Number of matching: " << matching << endl;

    if (matching == SIZE)
        cout << "Congratulations! You are a winner!" << endl;

    return 0;
}

void createRandom(int nums[])
{
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % (MAX_VAL + 1);
        cout << nums[i] << '\t';
    }
    cout << endl;
}

void getUserInput(int nums[])
{
    cout << "(Add space between each integer ) Enter " << SIZE << " numbers between 0 and " << MAX_VAL << ":" << endl;
    for (int i = 0; i < SIZE; i++)
        cin >> nums[i];
}

int countMatching(int nums1[], int nums2[])
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (nums1[i] == nums2[i])
            count++;
    }
    return count;
}





//#include <iostream>
//#include <string>
//#include <random>
//using namespace std;
//
//int translate(char seq[]) {
//    int weights[] = { 7, 4, 2, 1, 0 };
//    int total = 0;
//    for (int i = 0; i < 5; i++) {
//        total += (seq[i] - '0') * weights[i];
//    }
//    if (total == 11) {
//        return 0;
//    }
//    else {
//        return total;
//    }
//}
//
//string processCode(string inputCode) {
//    string postalCode = "";
//    char subGroup[6] = "";
//    int subIndex = 0;
//    for (int i = 1; i < 26; i++) {
//        subGroup[subIndex++] = inputCode[i];
//        if (subIndex == 5) {
//            subGroup[subIndex] = '\0';
//            int number = translate(subGroup);
//            postalCode += to_string(number);
//            subIndex = 0;
//        }
//    }
//    return postalCode;
//}
//
//int main() {
//    char inputCode[28] = "1";
//    random_device rd;
//    mt19937 generator(rd());
//    uniform_int_distribution<int> distribution(0, 1);
//    for (int i = 1; i < 26; i++) {
//        inputCode[i] = distribution(generator) + '0';
//    }
//    inputCode[26] = '1';
//    inputCode[27] = '\0';
//
//    cout << "Generated barcode: " << inputCode << endl;
//
//    string postalCode = processCode(inputCode);
//    postalCode = postalCode.substr(0, 5);
//    cout << "Zip code: " << postalCode << endl;
//
//    return 0;
//}
