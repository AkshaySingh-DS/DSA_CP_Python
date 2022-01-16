/* Problem Statement: https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0
Time Complexity : O(2^n) */

#include <iostream>
#include <vector>

using namespace std;

void allsubsequences(vector<string> &ans, string output, string str, int idx){
    
    //base case
    if (idx >= str.size()){
        if (output != ""){
            ans.push_back(output);
        }
        return;
    }
    
     //exclude character
    allsubsequences(ans, output, str, idx + 1);
    
    //include character
    output.push_back(str[idx]);
    allsubsequences(ans, output, str, idx + 1);
    
    //backtracking step not needed since ouput is pass by value not a reference
    //output.pop_back();
}

vector<string> subsequences(string str){
	
	// Write your code here
    string output;
    int indx = 0;
    vector <string> ans;  
    allsubsequences(ans, output, str, indx);
    return ans;	
}



