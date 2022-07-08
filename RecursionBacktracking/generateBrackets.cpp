#include <iostream>
using namespace std;

/* Problem Statement: Given an integer N representing the number of pairs of parentheses, the task is to 
generate all combinations of well-formed(balanced) parentheses.
https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

Time Complexity: O(2^N * N)
Space complexity: O(2^N * N)

Below Solution is without backtracking
 */


void generateBalancedBrackets(int opencnt, int closecnt, int n, string ans){

    //base case when both bracket count reached to n  
    if(opencnt == n and closecnt == n){
        cout << ans << endl;
        return;
    }
    //rec case
    
    //include the opening bracket only when it is less than N
    if (opencnt < n)
        generateBalancedBrackets(opencnt + 1, closecnt, n, ans + '(');
    
    //include the closing bracket only when it is less than opening bracket
    if(closecnt < opencnt) 
        generateBalancedBrackets(opencnt, closecnt + 1, n, ans + ')');

}
int main(){
    int n;
    cin >> n;
    generateBalancedBrackets(0, 0, n, "");  

    return 0;
}