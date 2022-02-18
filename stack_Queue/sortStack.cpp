/* 
Problem statement : https://www.codingninjas.com/codestudio/problems/abc_1229513
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

#include <iostream>
#include <stack>
using namespace std;

void insertInSortedStack(stack<int> &s, int k){
    
    //base case
    //if empty stack, element k is bigger than the top element then just push in stack
    if(s.empty() or s.top() < k){ 
       s.push(k);
       return;
    }
    
    //recursive case, if k is less than top of the element then keep popping the top
    int top = s.top();
    s.pop();
    
    insertInSortedStack(s, k); 
    
    //after the unsorted k element insertion, push the top in to stack
    s.push(top);
}
void sortStackHelper(stack <int> &s){
    //base case
    if (s.empty())
        return;
   
    //recursive case
    int top = s.top();
    s.pop();
    
    //sort the stack
    sortStackHelper(s);
    
    //insert th to element in sorted stack
    insertInSortedStack(s, top);    
}

stack<int> sortStack(stack<int> &s){
    
    sortStackHelper(s);
    return s;
}