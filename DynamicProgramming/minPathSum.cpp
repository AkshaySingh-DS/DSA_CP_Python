/* https://leetcode.com/problems/minimum-path-sum/
 */

#include <iostream>
#include<limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int solveRec(int i, int j, vector<vector<int>> &grid,  vector<vector<int>> &dp){
        
        //base case
        if(i == 0 and j == 0) return grid[0][0];
        
        //edge case
        if(i < 0 or j < 0) return INT_MAX;
         
        //rec case 
        if(dp[i][j] == -1){
            
            //calc for up move
            int upMove = grid[i][j];
            int cost = solveRec(i-1, j, grid, dp);
            if(cost != INT_MAX) upMove += cost;
            else upMove = INT_MAX;
            
            //calc for left move
            int leftMove = grid[i][j];  
            cost = solveRec(i, j-1, grid, dp);
            if(cost != INT_MAX) leftMove += cost;
            else leftMove = INT_MAX;
            
            dp[i][j] = min(upMove, leftMove);
        }
        
        return dp[i][j];
    }

    int minPathSumMem(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(); 
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solveRec(m-1, n-1, grid, dp);
    }
    
    //tebulation
    //time complexity :  O(m*n), Space Complexity: O(m*n) for DP array.
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(); 
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m ; i++){
            
             for(int j = 0; j < n ; j++){
                
                int up = 1e8;
                int left = 1e8;
                 
                if (i == 0 and j == 0) dp[0][0] = grid[0][0];
                 
                else {
                    
                    if(i > 0)
                        up = grid[i][j] + dp[i-1][j];
                 
                    if(j > 0)
                        left = grid[i][j] + dp[i][j-1];
                
                    dp[i][j] = min(left, up);
                }                 
            }
     
        }
        return  dp[m-1][n-1];
    }

    //Tabulation : space optimization from O(m*n) to O(n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        //vector<vector<int>> dp(m, vector<int>(n));
        vector<int> prev(n);
        
        for(int i = 0; i < m ; i++){
            
            vector<int> curr(n);
            
             for(int j = 0; j < n ; j++){
                
                int up = 1e8;//instead of INT_MAX since that will lead to overflow
                int left = 1e8;
                 
                if (i == 0 and j == 0) curr[0] = grid[0][0];
                 
                else {
                    
                    if(i > 0)
                        up = grid[i][j] + prev[j];
                 
                    if(j > 0)
                        left = grid[i][j] + curr[j-1];
                
                    curr[j] = min(left, up);
                }                 
            }
            prev = curr;
        } 
        return  prev[n-1];
    }
};