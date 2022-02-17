/* 
Problem statement : https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875
Time Complexity: O(N^2)
Space Complexity: O(2N)
*/

//using two stack approach we can also solve this problem
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack, int x){
    
    //base case 
    if(stack.empty()){
        stack.push(x);
        return;
    }
    
    //recursive case
    
    int top = stack.top();
    stack.pop();
    
    insertAtBottom(stack, x);
    //again push the top element
    stack.push(top);  
}
void reverseStack(stack<int> &stack) {
    //base case
    if (stack.empty()) 
        return ;
 
    //recursive case
    //save top of stack and reverse the rest elemnt of stack, willadd the at bottom of stack
    int top = stack.top();
    stack.pop();
    
    reverseStack(stack);
    
    //now insert the top element to the revrsed stack
    insertAtBottom(stack, top);
}