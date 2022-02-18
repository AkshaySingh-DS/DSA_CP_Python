/* 
Problem Statement :https://leetcode.com/problems/valid-parentheses/
Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
    bool match(char ch, char top){
    
    if ((top == '(' and ch == ')') or (top == '{' and ch == '}') or (top == '[' and ch == ']'))
        return true;
    
    return false;
    
}
public:
    bool isValid(string s) {
        
        //create stack to push all the openieng brackets
        stack <char> st;

        //traverse the expression
        for (auto ch : s){

            //push only the openning brackets
            if (ch == '(' or ch == '{' or ch == '[')        
                st.push(ch);

           //if stack is not empty and top of stack matches with their corresponding closing brackets then fine else invalid exprn 	
            else if ( !st.empty() and match(ch, st.top()))
                //keep on popping if match
                st.pop();

            //not a valid parenthesis 
            else return false;
        }

        //return true all if stack matches that means there is no elements left in stack
        if (st.empty())
            return true;
        else
            return false;
        }
};