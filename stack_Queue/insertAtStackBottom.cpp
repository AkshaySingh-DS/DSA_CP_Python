/* 
Problem Statement : https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166
Time Complexity: O(N)
Space Complexity: O(N)

Approach : try to save the top element then pop it, and then insert at bottom then again start pushing onto stack 
*/

#include <iostream>
#include <stck>
using namespace std;

void solve(stack<int>& myStack, int k){
    //base case
    if (myStack.empty()){
        
        myStack.push(k);
        return;
    }
    
    //recursive case
    //save the top element first
    int x = myStack.top();
    myStack.pop();
    
    solve(myStack, k);
    
    //again push the saved element
	myStack.push(x);
    
}
stack<int> pushAtBottom(stack<int>& myStack, int x) { 
    
    solve(myStack, x);  
    return myStack;
}


