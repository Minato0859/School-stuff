#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <string>
#include <vector>
#include <cmath>
using namespace std;




void into_vector(vector<int>& digits, int passpin);
bool check_password(vector<int> digits, int random_pin[], int password[],
	int array_size, int pin_size);


int main() {
	const int array_size = 10, pin_size = 5;
	const int order_pin[array_size] = { 0,1,2,3,4,5,6,7,8,9 };
	int random_pin[array_size], set_password, password[pin_size], passpin;
	vector<int> digits;
	bool password_is_correct = false;

	cout << "SET PASSWORD: ";
	cin >> set_password;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

	for (int i = 4; i >=0; i--) //put input into an array
		password[4-i] = (set_password / (static_cast<int>(pow(10, i)))) %10; //BRUHHH I COULDA BEEN USING THIS THE ENTIRE TIMEE?
	
	//for (int val : password)
	//	cout << val << endl;

	cout << "Pin: ";
	for (int val : order_pin)
		cout << val;

	cout << endl << "Num: ";

	srand(time(NULL)); // initialize random seed

	for (int& x : random_pin) {
		x = rand() % 3 + 1; // generate a random integer between 1 to 3 and store it in the array
	}
	for (int val : random_pin)
		cout << val;

	cout << "\nPassword: ";
	cin >> passpin;

	into_vector(digits, passpin);

	password_is_correct = check_password(digits,random_pin, password,
		array_size, pin_size); 

	if (password_is_correct == true)
		cout << "\nWelcome, you are being logged in...\n";
	if(password_is_correct ==false)
		cout << "\nPassword is incorrect\n";

}

void into_vector(vector<int>& digits, int passpin) {  //put passpin into an vector

	// Convert the integer to a string
	string passpin_str = to_string(passpin);


	// Iterate through the string and store the digits in the vector
	for (char digit_char : passpin_str) {
		int digit = digit_char - '0'; // Convert the character to its corresponding integer value
		digits.push_back(digit);
	}

	/*cout << "Input Digits: ";
	for (int digit : digits) {
		cout << digit << "";
	}
	cout << endl;*/

}
bool check_password(vector<int> digits, int random_pin[], int password[], int array_size, int pin_size)
{
	bool password_is_correct = true;
	bool correct_pass[5] = { false,false,false,false,false };
	bool verify[5] = { true, true, true, true, true };//or we coulda used a do while loop, to exit if it becomes false even once but whatever
	int element_counter = 0;

	for (int i : digits) 
	{
		if (i == random_pin[(password[element_counter])])
			correct_pass[element_counter] = true;

		element_counter += 1;

	}

	for (int i = 0; i < pin_size; i++)

		if (correct_pass[i] != verify[i])
			password_is_correct = false;

	return password_is_correct;

}