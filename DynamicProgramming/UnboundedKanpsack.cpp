/* 
Problem link: 
https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029 
*/

#include <iostream>
#include <vector>
using namespace std;

//Approach - Recursion
//Time Complexity: O(2^N) 
//Space Complexity: Aux recursive Stack -> O(N)
int solveRec(vector<int> &profit, vector<int> &weight, int i, int w){
    
    //base case
    if (i == 0) {
        return int(w/weight[0]) * profit[0];
    }
    //rec case
    int notpick = 0 + solveRec(profit, weight, i-1, w);
    
    int pick = -1e8;
    
    if(weight[i] <= w) pick = profit[i] + solveRec(profit, weight, i, w - weight[i]);
    
    return max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
     
    return solveRec(profit, weight, n-1, w);
}

//Approach - Memoization (Top Down DP)
//Time Complexity: O(N * W) 
//Space Complexity: Aux recursive Stack -> O(N)+ O(N * W) for dp array
int solveMem(vector<int> &profit, vector<int> &weight, int i, int w,  vector<vector<int>> &dp){
    
    //base case
    if (i == 0) {
        return int(w/weight[0]) * profit[0];
    }
    //rec case
    if(dp[i][w] == -1){
        int notpick = 0 + solveMem(profit, weight, i-1, w, dp);
    
        int pick = -1e8;

        if(weight[i] <= w) pick = profit[i] + solveMem(profit, weight, i, w - weight[i], dp);

        dp[i][w] =  max(pick, notpick);
    }
    
    return dp[i][w];
    
}

int unboundedKnapsack2(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solveMem(profit, weight, n-1, w, dp);
}


//Approach - tabulation (Bottom UP DP)
//Time Complexity: O(N * W) 
//Space Complexity: O(N * W) for dp array
int unboundedKnapsack3(int n, int w, vector<int> &profit, vector<int> &weights){
    
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    
    //base cases
    for(int weight = 0 ; weight < w + 1; weight++)   
        dp[0][weight] = int(weight/weights[0]) * profit[0];
        
     for(int i = 1; i < n ; i++){
         
         for(int weight = 0; weight < w + 1; weight++){
             
             int notpick = 0 + dp[i-1][weight];
    
             int pick = -1e8;

             if(weights[i] <= weight) pick = profit[i] + dp[i][weight - weights[i]];

             dp[i][weight] =  max(pick, notpick);            
         }
     }
    
    return dp[n-1][w];
}


//Approach - tabulation (Bottom UP DP with space optimization)
//Time Complexity: O(N * W) 
//Space Complexity: O(w) instead of 2-d dp (N * M) aaray
int unboundedKnapsack4(int n, int w, vector<int> &profit, vector<int> &weights){
    
    vector <int> prev(w+1, 0);
    vector <int> curr(w+1, 0);
    
    //base cases
    for(int weight = 0 ; weight < w + 1; weight++)   
        prev[weight] = int(weight/weights[0]) * profit[0];
        
     for(int i = 1; i < n ; i++){
         
         for(int weight = 0; weight < w + 1; weight++){
             
             int notpick = 0 + prev[weight];
    
             int pick = -1e8;

             if(weights[i] <= weight) pick = profit[i] + curr[weight - weights[i]];

             curr[weight] =  max(pick, notpick);            
         }
         
         prev = curr;
     }
    
    return prev[w];
}