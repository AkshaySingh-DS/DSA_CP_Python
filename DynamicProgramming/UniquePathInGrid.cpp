/* https://leetcode.com/problems/unique-paths/ */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    //using plane recursion
    //Time complexity : O(2^M*N), space complexity : O(m + n)
    int solveRec(int i, int j){
        
        //base case
        if(i == 0 and j == 0) return 1;
            
        //edge case i.e. invalid location
        if(i < 0 or j < 0) return 0;
        
        //rec case 
        int leftMoveCnt = solveRec(i, j-1);
        int rightMoveCnt = solveRec(i-1, j);
        
        return leftMoveCnt + rightMoveCnt;
        
    }
    //Using Memoization
     //time complexity : O(m+n), space complexity : O(m+n) rec stack and dp array O(m*n) -> O(m*n)
    int solveMem(int i, int j, vector<vector<int>> &dp){
        
        //base case
        if( i== 0 and j == 0) return 1;
            
        //edge case i.e. invalid location
        if(i < 0 or j < 0) return 0;
        
        //rec case 
        if(dp[i][j] == -1){
            
             int leftMoveCnt = solveMem(i, j-1, dp);
             int rightMoveCnt = solveMem(i-1, j, dp);
                
            dp[i][j] = leftMoveCnt + rightMoveCnt;
        } 
       
        return dp[i][j];
        
    }

//Using tabulation 
//Time Complexity : O(n*m), O(n*m) for dp array 
int uniquePathsTab(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(i == 0 and j == 0) dp[0][0] = 1;
                
                if(i-1 >= 0) dp[i][j] = dp[i-1][j];
                if(j-1 >= 0) dp[i][j] += dp[i][j-1];
            
            }            
        }
        return dp[m-1][n-1];       
    }

    //Space Optimization tabulation
    //time complexity : O(n*m), space complexity : O(n)
    int uniquePaths(int m, int n) {
        vector<int> curr(n);
        vector<int> prev(n);

        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(i == 0 and j == 0) curr[0]= 1;
                
                if(i-1 >= 0) curr[j] = prev[j];
                if(j-1 >= 0) curr[j] += curr[j-1];
            
            }    
            prev = curr;
        }
        return curr[n-1];       
    }
    int uniquePaths(int m, int n) {
        //return solveRec(m-1, n-1); 
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMem(m-1, n-1, dp);       
    }  
};