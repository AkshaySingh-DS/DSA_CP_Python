/* Problem Statement:
Time Complexity : O(4^n)
where n is characters in given strings */

#include <iostream>
#include <vector>
using namespace std;
class Solution {

private:
    void keyPad_Solve(vector <string> &ans, string output, int idx, string keymap [], string digits){
        
        //base case
        if(idx >= digits.length()){  
            //edge case
            if (output == ""){
                return;
            }
            ans.push_back(output);
            return;
        }
        
        int num = digits[idx] - '0';
        string values = keymap[num];
        
        for(int i = 0 ; i < values.size(); i++){
            
            output.push_back(values[i]);
            
            keyPad_Solve(ans, output, idx + 1, keymap, digits);
            
            //backtracking
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector <string> ans;
        string output;
        int idx = 0;
        //string of string
        string keymap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
         
        keyPad_Solve(ans, output, idx, keymap, digits);
        return ans;
        
    }
};