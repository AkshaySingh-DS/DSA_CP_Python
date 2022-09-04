/* https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */

#include <vector>
#include <iostream>
using namespace std;


/*
logic : i) what stopping to make string L to be a palindrome ?
ii) what could be the maximum (on an avg) insertion we can make to make any string as palindrome 
For Ex: str = abcde then -> str + rev(str) -> abcdeedcba, hence on max len(str) are the insertions require to make str palindrome.
iii) Now, if we find the maximum longest palindromic subsequence in a string then rest are the characters which are stoping to being the string as palindrome isn't it? hence 
minimum # of insertion would be = len(str) - length of longest palindromic subsequence
Approach : Bottom Up DP (idea of longest common subsequences)
*/

//Time Complexity : O(n^2)
//Space Complexity : O(n^2) 
class Solution1{
public:
    int Lps(string s1, string s, int n){ 
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); //1 based indexing (covered the base cases)
        for(int i = 1; i < n + 1; i++){ 

            for(int j = 1; j < n + 1; j++){

                if(s1[i-1] == s[j-1])   dp[i][j] = 1 + dp[i-1][j-1];

                else{
                    if(dp[i-1][j] >= dp[i][j-1]) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-1];                    
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int len  = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        int lps = Lps(s1, s, len); //longest palindromic subsequence
        return len - lps;
    }
};

//Time Complexity : O(n^2)
//Space Complexity : O(n) 
class Solution2 {
public:
    int Lps(string s1, string s, int n){ 
        
        //vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); //1 based indexing (covered the base cases)
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for(int i = 1; i < n + 1; i++){
            
            for(int j = 1; j < n + 1; j++){
                
                if(s1[i-1] == s[j-1])   curr[j] = 1 + prev[j-1];
            
                else{
                    
                    if(prev[j] >= curr[j-1]) curr[j] = prev[j];
                    else curr[j] = curr[j-1];                    
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
    int minInsertions(string s) {
        
        int len  = s.length();
        
        string s1 = s;
        reverse(s.begin(), s.end());
        
        int lps = Lps(s1, s, len); //longest palindromic subsequence
        
        return len - lps;
    }
};