
/* https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=1 */

#include <iostream>
#include <vector>
using namespace std;

//using Recursion
//Time Complexity : O(2^n), Space Complexity : O(n) of Rec stack.
int solveRec(vector<vector<int>>& triangle, int i, int j, int n){
    
    //base case
    if(i == n - 1){
        return triangle[i][j];
    }

    //rec case
    int blow = triangle[i][j] + solveRec(triangle, i+1, j, n);
    int diag = triangle[i][j] + solveRec(triangle, i+1, j+1, n);
        
   return  min(blow, diag);  

}

//using Memoization
//Time Complexity : O(n * n), Space Complexity : O(n) of Rec stack + O(n^2) for dp array.
int solveMem(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>> &dp){
    
    //base case
    if(i == n - 1){
        return triangle[i][j];
    }

    //rec case
    if (dp[i][j] == -1){
        int blow = triangle[i][j] + solveMem(triangle, i+1, j, n, dp);
        int diag = triangle[i][j] + solveMem(triangle, i+1, j+1, n, dp);
        
        dp[i][j] = min(blow, diag);  
    }
    return dp[i][j];
}

//tabulation  approach
//Time Complexity : O(n * n), Space Complexity:  O(n^2) for dp array.
int minimumPathSumTab(vector<vector<int>>& triangle, int n){
	
    vector<vector<int>> dp(n, vector<int>(n));
    
    //base case
    for(int j = 0; j < n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    //rec case aka tabulation approach
    
    for(int i = n-2; i >= 0; i--){
        
        for(int j = 0; j <= i ; j++){
            
            int blowStep = triangle[i][j] + dp[i+1][j];
            int diagStep = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(blowStep, diagStep);  
        }
    }
    
    return dp[0][0];
} 

//Tabulation  approach
//Time Complexity : O(n * n), Space Complexity:  O(n) for dp array.
int minimumPathSum(vector<vector<int>>& triangle, int n){
	
    vector<int> next(n);
    
    //base case
    for(int j = 0; j < n; j++)  next[j] = triangle[n-1][j];
   
    //rec case aka tabulation approach
    vector <int> curr(n);
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i ; j++){
            
            int blowStep = triangle[i][j] + next[j];
            int diagStep = triangle[i][j] + next[j+1];

            curr[j] = min(blowStep, diagStep);  
        }
        
        next = curr;
    }
    
    return next[0];
} 



int minimumPathSum(vector<vector<int>>& triangle, int n){
	
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMem(triangle, 0, 0, n, dp);
    //return solveRec(triangle, 0, 0, n);
}

