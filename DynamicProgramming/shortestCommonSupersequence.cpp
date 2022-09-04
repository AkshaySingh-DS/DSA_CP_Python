/* https://leetcode.com/problems/shortest-common-supersequence/ */

/*
Logic:h on an average common supersequence would be str1 + str2, but str1 and str2 may have some common subsequences has they have included in above twice. So if we remove the LCS(str1, str2) from above then will have the shortest common supersequence

Time Complexity : O(N * M)
Time Complexity : O(N * M) due to dp array

*/

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // base covered here in initialization step
        
        for(int i = 1 ;i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){

                 if(str1[i-1] == str2[j-1]) dp[i][j]  = 1 + dp[i-1][j-1];
                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int ptr = n + m - dp[n][m] - 1; // len of Shortest Common Supersequence will be ptr + 1
        string ans;
        for(int  i = 0; i < ptr + 1; i++)  ans.push_back('$');
        
        //now do the backtracking to get the required SCS on dp vector
        int i = n, j = m; 
        
        while(i > 0 and j > 0){
            
            if(str1[i-1] == str2[j-1]){ //1 based indexing on dp array
                
                ans[ptr--] = str1[i-1];
                i--; j--;
            } 
            else{
                
                if(dp[i-1][j] >= dp[i][j-1]){
                    
                    ans[ptr--] = str1[i-1];
                    i--;
                }
                else{
                    
                    ans[ptr--] = str2[j-1];
                    j--;
                }
            }  
        }
        
        //append all character of str2 which are left
        while( j > 0 and i == 0){
            ans[ptr--] = str2[j-1];
            j--;
        }
        //append all character of str1 which are left
        while( i > 0 and j == 0){
            ans[ptr--] = str1[i-1];
            i--;
        }
        return ans;
    }
};