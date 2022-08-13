/* 
https://leetcode.com/problems/unique-paths-ii/ 
*/

#include <iostream>
#include <vector>
#define MOD 2000000001
using namespace std;

class Solution {
public:

    //memoized DP
    //time complexity : O(N*M) ,space complexity : O(N+M) recursion stack + O(N*M) dp array -> O(N*M)
    int solveRec(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp){
        
        //edge case
        if(i < 0 or j < 0 or obstacleGrid[i][j] == 1) return 0;
        
        //base case
        if(i == 0 and j == 0) return 1;
        
        //rec case
        if (dp[i][j] == -1){
            
            int upMove = solveRec(obstacleGrid, i-1, j, dp);
            int leftMove =  solveRec(obstacleGrid, i, j-1, dp);
            
            dp[i][j] = upMove + leftMove;
        } 
        
        return dp[i][j];
        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveRec(obstacleGrid, n-1, m-1, dp);
        
    }

    //Tabulation aka bottom up Approach:
    //space complexity : O(M*N) of dp array,  Time Complexity: O(M*N)
    int uniquePathsWithObstaclesTab(vector<vector<int>>& obstacleGrid){
        
        //edge case
        if (obstacleGrid[0][0] == 1) return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(i > 0 and obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i-1][j];
                if(j > 0 and obstacleGrid[i][j] != 1)
                    dp[i][j] +=  dp[i][j-1];
                
            }
        }
        
        return dp[n-1][m-1];
    }

    //tabulation with space optimization 
    // Space Complexity : O(m), i.e. number of columns in a grid
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        
        //edge case
        if (obstacleGrid[0][0] == 1) return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<int> prev(m, 0);
        
        for(int i = 0; i < n; i++){
            
            vector<int> curr(m, 0); // have to clear this for every row
            
            for(int j = 0; j < m; j++){
                
                if (i == 0 and j == 0) curr[j] = 1;
                
                if(i > 0 and obstacleGrid[i][j] != 1)
                    curr[j] = prev[j];
                
                if(j > 0 and obstacleGrid[i][j] != 1)
                    curr[j] +=  curr[j-1];
                
            }
            prev = curr;    
        }
        return prev[m-1] % MOD;
    }
};
