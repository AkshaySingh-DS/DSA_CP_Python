#include <iostream>
using namespace std;
/* 
Problem Statement: Given an integer N representing the number of pairs of parentheses, the task is to 
generate all combinations of well-formed(balanced) parentheses and as well as count all balanced brackets. 

Time Complexity: O(2^N * N)
Space complexity: O(2^N * N)
Below Solution is with backtracking
*/


int generateBalancedBrackets(int opencnt, int closecnt, int n, string ans){

    //base case when both bracket count reached to n  
    if(opencnt == n and closecnt == n){
        cout << ans << endl; 
        return 1;
    }
    //rec case
    int cntways = 0;
    //include the opening bracket only when it is less than N
    if (opencnt < n){
        ans.push_back('(');
        cntways += generateBalancedBrackets(opencnt + 1, closecnt, n, ans);
        ans.pop_back();//backtrack for further calls
    }
    
    //include the closing bracket only when it is less than opening bracket
    if(closecnt < opencnt) {
        ans.push_back(')');
        cntways += generateBalancedBrackets(opencnt, closecnt + 1, n, ans);
        ans.pop_back();//backtrack for further calls
    }
    
    return cntways;
}
int main(){
    int n;
    cin >> n;
    int cnt = generateBalancedBrackets(0, 0, n, "");  
    cout<< "Total Number of balanced Paranthesis is : " << cnt << endl;

    return 0;
}