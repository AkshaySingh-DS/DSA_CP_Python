#include <iostream>
using namespace std;

//using tail recursion
void increasing(int number){

    //base 
    if (number == 0) return;

    //rec case
    increasing(number-1);
    cout << number << "  ";

}
void decreasing(int num){

    //base
    if (num == 0) return;

    //rec case
    cout << num << "  ";
    decreasing(num-1);
    
}
int main(){

    int number;
    cin >> number;
    
    decreasing(number);
    cout << endl ;
    
    increasing(number);
    return 0;
}