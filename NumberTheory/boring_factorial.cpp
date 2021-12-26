/*
Problem statement: https://www.codingninjas.com/codestudio/problems/boring-factorials_1474978?leftPanelTab=1
Time complexity : O(N)
Space complexity : O(1)
*/
#include <iostream>
using namespace std;

int factorialMod(int n, int m){

    // Write your code here.
    int result_ = 1;
    
    while(n){
        
        result_ = (result_ * n) % m;
        n--;
    }
    return result_;
}
int main(){
    
    
    int testcases;
    cin >> testcases;
    while (testcases--){
        int k, p;
        cin >> k >> p;
        cout << factorialMod(k, p) << endl;  
    }
    
    return 0;
}


/*
Python Solution:
import sys
def factorialMod(k ,m):
    #logic
    result_ = 1
    for val in range(1, k+1):
        result_ = (result_ * val) % m    
    return result_

#code start from here
testcases = int(sys.stdin.readline().strip())
while testcases:
    k, m = map(int, sys.stdin.readline().strip().split())
    print(factorialMod(k ,m))
    testcases -= 1
*/