/* 
Problem link: 
https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
*/

#include <iostream>
#include <vector>
using namespace std;

//Approach - Recursion
//Time Complexity: O(2^N) 
//Space Complexity: Aux recursive Stack -> O(N)
int solveRec(vector<int> &price, int i, int length){
    //base case
    if(i == 0)
        return length * price[0];
    
    //rec case
    int notpick = 0 + solveRec(price, i-1, length);
    
    int pick = -1e8;
    
    if(i+1 <= length) pick = price[i] + solveRec(price, i, length - (i+1)); //1 based indexing
    
    return max(pick, notpick);
}
int cutRod(vector<int> &price, int n){

    return solveRec(price, n-1, n);
}

//Approach - Memoization (Top Down DP)
//Time Complexity: O(N * N) 
//Space Complexity: Aux recursive Stack -> O(N)+ O(N * N) for dp array
int solveMem(vector<int> &price, int i, int length,  vector<vector<int>> &dp){
    //base case
    if(i == 0)
        return length * price[0];
    
    //rec case
    if(dp[i][length] == -1){
        int notpick = 0 + solveMem(price, i-1, length, dp);
    
        int pick = -1e8;

        if(i+1 <= length) pick = price[i] + solveMem(price, i, length - (i+1), dp); //1 based indexing

        dp[i][length] = max(pick, notpick);
    }
    
    return dp[i][length];
}
int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solveMem(price, n-1, n, dp);
}

//Approach - tabulation (Bottom UP DP)
//Time Complexity: O(N * N) 
//Space Complexity: O(N * N) for dp array
int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    
    //base case
    for(int l = 0 ; l < n + 1; l++)   
        dp[0][l] = l * price[0];
    
    for(int i = 1; i < n ; i++){
         
         for(int length = 0; length < n + 1; length++){
             
            int notpick = 0 + dp[i-1][length];
    
            int pick = -1e8;

            if(i+1 <= length) pick = price[i] + dp[i][length - (i+1)]; //1 based indexing

            dp[i][length] = max(pick, notpick);           
         }
     }
    
    return dp[n-1][n];
}


//Approach - tabulation (Bottom UP DP with space optimization)
//Time Complexity: O(N * N) 
//Space Complexity: O(N) instead of 2-d dp (N * N) aaray
int cutRod(vector<int> &price, int n){
    vector <int> prev(n+1, 0);
    vector <int> curr(n+1, 0);
    //base case
    for(int l = 0 ; l < n + 1; l++)   
        prev[l] = l * price[0];
    
    for(int i = 1; i < n ; i++){
         
         for(int length = 0; length < n + 1; length++){
             
            int notpick = 0 + prev[length];
    
            int pick = -1e8;

            if(i+1 <= length) pick = price[i] + curr[length - (i+1)]; //1 based indexing

            curr[length] = max(pick, notpick);           
         }
        
        prev = curr;
     }
    
    return prev[n];
}