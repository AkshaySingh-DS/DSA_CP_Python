/* 
Problem Statement : https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246
Time Complexity: O(N)
Space Complexity: O(N)
*/
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&inputStack, int cnt, int size){
    //base case
    if (cnt == size/2){
        inputStack.pop();
    	return; 
    }
    
    //recursive case
    int k = inputStack.top();
    inputStack.pop();
    
    solve(inputStack, cnt + 1, size);
    
    //push the above element
    inputStack.push(k);
}
void deleteMiddle(stack<int>&inputStack, int N){
	  
    
    solve(inputStack, 0, N);   
}
