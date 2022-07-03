#include <iostream>
using namespace std;

//time complexity : O(number) space complexity : O(number)
int pow(int a, int num){

    //base  case
    if (num == 0) return 1;

    //rec case
    return a * pow(a, num-1);

}

//time complexity : O(2^N) space complexity : O(logn)
//this will lead to exponetial 
int fastPower(int a, int num){

    //base case
    if (num == 0) return 1;

    //rec case unnecessary recursive calls
    if (num&1) return a * fastPower(a, num/2) * fastPower(a, num/2);

    else return fastPower(a, num/2) * fastPower(a, num/2); 
}

//this will not lead to exponetial because we are utlizing the subproblem 
//using tail recursion 
//time complexity : O(logN) space complexity : O(logn)
int fastPower(int a, int num){

    //base case
    if (num == 0) return 1;

    //rec case 
    int subproblem = fastPower(a, num/2);
    int sqSubproblem = subproblem * subproblem;

    //for odd 
    if (num&1) return a * sqSubproblem;
    
    //for even
    else return sqSubproblem; 
}


int main(){

    int a, num;
    cin >> a >> num;

    cout << pow(a, num) << endl;

    return 0;
}