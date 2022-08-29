#include <iostream>
#include<vector>
#include <unordered_map> //use this
using namespace std;

class Solution {
public:
    bool solveMem(string s, vector<string>& wordDict, unordered_map <int,bool> &dp, int i){
        
        //base case
        if(i == s.length()) return true;
        
        
        //memoization 
        if (dp.find(i) != dp.end()) return dp[i];
        
        //rec case
        for(auto word : wordDict){
            
            if(word == s.substr(i, word.length()) and solveMem(s, wordDict, dp, i+word.length())){
                
                dp[i + word.length()] = true;
                return true;
            }
        }
        
        dp[i] = false;
        return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //unordered_map <int, bool> dp;
        //return solveMem(s, wordDict, dp, 0);
        vector<bool>dp(s.length() + 1, false);
        dp[s.length()] = true;
        
        for(int i = s.length()-1; i >= 0; i--){
            
            for(auto word : wordDict){
                
                if(word.length() + i <= s.length() and (word == s.substr(i, word.length()))){
                    
                    dp[i] = dp[i + word.length()];
                
                }
                
                if (dp[i]) break;
            }
            
        }  
        
        return dp[0];      
    }
};