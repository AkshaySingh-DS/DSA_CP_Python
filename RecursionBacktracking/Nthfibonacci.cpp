/*
time complexity : O(number) -> O(2^n).
space complexity: O(number) due to recursion stack O(n)
*/

#include <iostream>
using namespace std;
int fibonacci(int number){

    //base case 
    if (number == 1) return 0;
    if (number == 2) return 1;

    //recursive case
    int fibo = fibonacci(number-1) + fibonacci(number-2);
    return fibo;
}

int main(){

    int num;
    cin >> num;

    cout << num << "th Fibonacci would be: "<< fibonacci(num) << endl;
    return 0;
}