/* 
problem link : https://leetcode.com/problems/longest-palindromic-subsequence/ 
*/

#include<iostream>
#include<vector>
using namespace std;

//Approach - Tabulation 
//Time Complexity: O(n^2) + O(n)
//Space Complexity: O(n^2) for dp array
class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        
        string rev_s = "";
        int n = s.length();
        
        //reverse the given string and then longest common subsquences for both will be longest palindrmoic 
        for(int i = n - 1; i >= 0; i--) rev_s.push_back(s[i]);
        
        vector <vector<int>> dp(n+1, vector<int>(n+1, 0)); //base cases are covered
        
        for(int i = 1; i < n + 1; i++){
            
            for(int j = 1; j < n + 1; j++){
                
                if(s[i-1] == rev_s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];  
    }
};


//Approach - Tabulation (space optimized)
//Time Complexity: O(n^2) 
//Space Complexity: O(n) for dp array
class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        
        string rev_s = s;
        int n = s.length();
    
        //reverse the given string and then longest common subsquences for both will be longest palindrmoic 
        reverse(s.begin(), s.end());
        
        vector <int> prev(n+1, 0); //base cases are covered
        vector <int> curr(n+1, 0);
        
        for(int i = 1; i < n + 1; i++){
            
            for(int j = 1; j < n + 1; j++){
                
                if(s[i-1] == rev_s[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            
            prev = curr;
        }
        
        return prev[n];  
    }
};