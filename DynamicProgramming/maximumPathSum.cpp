/* https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998 */

#include <iostream>
#include <vector>
using namespace std;

//Using Recursion
//Time Complexity: 3^n, space O(n) Recursive stack
int solveRec(int i, int j, vector<vector<int>> &matrix){
    
    //base case and edge case
    if(j < 0 or j >= matrix[0].size()) return -1e8;
    
    if(i == 0) return matrix[0][j];
    
    //rec case
    int st = matrix[i][j] + solveRec(i-1, j, matrix);
    int leftDiag = matrix[i][j] + solveRec(i-1, j-1, matrix);
    int rightDiag = matrix[i][j] + solveRec(i-1, j+1, matrix);
    
    return max(st, max(leftDiag, rightDiag));

}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e8;
    
    for(int j = 0; j < m; j++){
        
        maxi = max(maxi, solveRec(n-1, j, matrix));
    }
    
    return maxi;
}

//Memoized DP
//Time Complexity: O(n*m), space O(n) Recursive stack + O(n*m) dp array
int solveMem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    
    //base case and edge case
    if(j < 0 or j >= matrix[0].size()) return -1e8;
    
    if(i == 0) return matrix[0][j];
    
    //rec case
    if(dp[i][j] == -1){
        
        int st = matrix[i][j] + solveMem(i-1, j, matrix, dp);
        int leftDiag = matrix[i][j] + solveMem(i-1, j-1, matrix, dp);
        int rightDiag = matrix[i][j] + solveMem(i-1, j+1, matrix, dp);
        
        dp[i][j] = max(st, max(leftDiag, rightDiag));
    }
   
    return dp[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e8;
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int j = 0; j < m; j++){
        
        maxi = max(maxi, solveMem(n-1, j, matrix, dp));
    }
    
    return maxi;
}

//Tabulation
//Time Complexity: O(n*m), space O(n*m) dp array 
int getMaxPathSumTab(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1e8));
    
    for(int j = 0; j < m; j++)   dp[0][j] = matrix[0][j];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            
            int st = matrix[i][j] + dp[i-1][j];
            int leftDiag, rightDiag;
            leftDiag = rightDiag = -1e8;
            
            if(j-1 >= 0)   leftDiag = matrix[i][j] + dp[i-1][j-1];
            if(j+1 <= m-1)  rightDiag = matrix[i][j] + dp[i-1][j+1];
            
            dp[i][j] = max(st, max(leftDiag, rightDiag));
        }
    }
    
    int maxi = -1e9;
    for(int j = 0; j < m; j++) maxi = max(maxi, dp[n-1][j]);
    return maxi;
}

//Tabulation With space Optimization
//Time Complexity: O(n*m), space O(m) curr & Prev array 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    
    //vector<vector<int>> dp(n, vector<int>(m, -1e8));
    vector <int> prev(m, -1e8);
    
    for(int j = 0; j < m; j++)   prev[j] = matrix[0][j];
    
    for(int i = 1; i < n; i++){
        
        vector <int> curr(m, -1e8);
        
        for(int j = 0; j < m; j++){
            
            int st = matrix[i][j] + prev[j];
            int leftDiag, rightDiag;
            leftDiag = rightDiag = -1e8;
            
            if(j-1 >= 0)   leftDiag = matrix[i][j] + prev[j-1];
            if(j+1 <= m-1)  rightDiag = matrix[i][j] + prev[j+1];
            
            curr[j] = max(st, max(leftDiag, rightDiag));
        }
        
        prev = curr;
    }
    
    int maxi = -1e9;
    for(int j = 0; j < m; j++) maxi = max(maxi, prev[j]);
    return maxi;
}