/* 
Problem link: 
https://leetcode.com/problems/longest-common-subsequence/
*/

#include <iostream>
#include <vector>
using namespace std;

//Approach - Plane Recursion  -> TLE
//Time Complexity: O(2^(m+n))
//Space Complexity: Auxillary Recursive Stack (n + m)
//Base is easy to understand here by considering 0-based indexing
class Solution1 {
public:
    
    int solveRec(string s1, string s2, int i, int j){
        
        //base case
        if( i == -1 or j == -1) return 0;
        
        //rec case
        if(s1[i] == s2[j]) return 1 + solveRec(s1, s2, i-1, j-1);
        
        return max(solveRec(s1, s2, i-1, j), solveRec(s1, s2, i, j-1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        return solveRec(text1, text2, n-1, m-1);       
    }
};

//Approach - Memoization (Top Down DP) -> Giving TLE in memoization :)
//Time Complexity: O(n * m)
//Space Complexity: O(n*m) for dp array + Auxillary Rec Stack (n + m)
//Base is easy to understand here by considering 0-based indexing 
class Solution2 {
public:
    
    int solveMem(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        
        //base case
        if( i == -1 or j == -1) return 0;
        
        //rec case
        if(dp[i][j] == -1){
            
            if(s1[i] == s2[j]) dp[i][j]  = 1 + solveMem(s1, s2, i-1, j-1, dp);
            else dp[i][j] = max(solveMem(s1, s2, i-1, j, dp), solveMem(s1, s2, i, j-1, dp));
        }
        
        return dp[i][j];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveMem(text1, text2, n-1, m-1, dp);       
    }
};

//Approach - Memoization (Top Down DP) 
//Time Complexity: O(n * m)
//Space Complexity: O(n*m) for dp array + Auxillary Rec Stack (n + m)
//Making easier base case (for tabulation conversion) by shifting indexing right (right shifting 1 based indexing) 
class Solution3 {
public:
    
    int solveMem(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        
        //base case
        if( i == 0 or j == 0) return 0;
        
        //rec case
        if(dp[i][j] == -1){
            
            if(s1[i-1] == s2[j-1]) dp[i][j]  = 1 + solveMem(s1, s2, i-1, j-1, dp);
            else dp[i][j] = max(solveMem(s1, s2, i-1, j, dp), solveMem(s1, s2, i, j-1, dp));
        }
        
        return dp[i][j];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMem(text1, text2, n, m, dp);       
    }
};

//Approach - Tabulation 
//Time Complexity: O(n * m) + O(n+m)
//Space Complexity: O(n*m) for dp array
class Solution4 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //base cases
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m+1; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1 ;i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){

                 if(text1[i-1] == text2[j-1]) dp[i][j]  = 1 + dp[i-1][j-1];
                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return  dp[n][m];       
    }
};

//Approach - Tabulation (space optimized)
//Time Complexity: O(n * m) 
//Space Complexity: O(m) for dp array
class Solution4 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        //base cases are coverd below already in initialization
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        for(int i = 1 ;i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){

                 if(text1[i-1] == text2[j-1]) curr[j]  = 1 + prev[j-1];
                 else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];       
    }
};