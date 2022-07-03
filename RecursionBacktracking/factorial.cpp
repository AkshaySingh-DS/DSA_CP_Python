/*
time complexity : O(number) -> there are n calls.
space complexity: O(number) due to recursion stack
*/

#include <iostream>
using namespace std;
int factorial(int number){

    //base case 
    if (number == 0) return 1;

    //recursive case
    int fact = number * factorial(number-1);
    return fact;
}

int main(){

    int number;
    cin >> number;

    cout << "factorial of " << number << " is: " << factorial(number) << endl;
    return 0;
}