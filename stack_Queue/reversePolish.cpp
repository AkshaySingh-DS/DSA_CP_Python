/* 
Problem Statement : https://leetcode.com/problems/evaluate-reverse-polish-notation/
Time Complexity: O(N)
Space Complexity: O(N)

Approach1 : Using Explicit stack

Approach2 : Using implicit stack

Approach 3: space complexity O(1), using input vector as stack. */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
private:
    bool isOperator(string ch){
        
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "%")
            return true;
        
        return false;
    }
    
    int evaluate(int a, int b, string opr){
        
        if (opr == "+")
          return a + b;
        
        else if (opr == "-")
          return a - b;
        
        else if (opr == "*")
            return a * b;
        
        else if (opr == "/")
            return a / b;
        
        return a % b;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        
        stack <int> s;
        
        for (int i = 0 ; i < tokens.size(); i++){
            
            if(!isOperator(tokens[i])){
                
                s.push(stoi(tokens[i]));
            }
            
            else{
                
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
                s.push(evaluate(a, b, tokens[i]));
            }
        }
        
        return s.top() ;   
    }
};