#include <iostream>
using namespace std;

int main()
{
    int counter = 0;
    int number; 
    int largest; 
    int secondLargest; 

    cout << "Enter the first number: ";
    cin >> largest;

    cout << "Enter next number: "; 
    cin >> number;
    
    if (number > largest)
    {
        
        largest = number;
    } 

    if (number = largest)
    counter += 1; 

    
    while (number != -9999)
    {
        cout << "Enter next number: "; 
        cin >> number; 

       
        if (number > largest)
        {
           
            largest = number;
        } 
        else if (number == largest)
            counter += 1;

        
    } 

   
    cout << "\nLargest is " << largest << " and occured " << counter << " times" <<  endl;
    return 0;
} 