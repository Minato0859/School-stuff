#include <iostream>
using namespace std;

int main()
{
	double score1, score2, score3, score4, score5, average;

	cout << "Please input 5 scores : ";
	cin >> score1 >> score2 >> score3 >> score4 >> score5;

	average = (score1 + score2 + score3 + score4 + score5) / 5.0;


	cout << "\nThe Average score is: " << average << endl;

	return 0;
}