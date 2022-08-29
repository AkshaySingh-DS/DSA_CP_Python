/* https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954 */

#include <iostream>
#include <vector>
using namespace std;

//method plaine Recursion
//time complexity : O(2^target)
//space complexity : O(n) where n is the number of elements f
bool solveRec(vector<int> &arr, int target, int i){
    //base case
    if(target == 0) return true;
    
    if(i == 0) return arr[0] == target; 
    
    //rec case
    bool notpick = solveRec(arr, target, i-1);
    
    bool pick = false;
    if(arr[i] <= target)
        pick = solveRec(arr, target - arr[i], i-1);
    
    return pick or notpick;
   
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return solveRec(arr, k, n-1);
}

//Method Top down dp(Memoization) - Recursion
//time complexity : O(target)
//space complexity : O(n) where n is the number of elements
int solveRecMem(vector<int> &arr, int target, int i, vector<vector<int>> &dp){
    //base case
    if(target == 0) return true;
    if(i == 0) return arr[0] == target; 
    
    //rec case  
    if(dp[i][target] == -1){
        bool notpick = solveRecMem(arr, target, i-1, dp);
        bool pick = false;
        
        if(arr[i] <= target)
              pick = solveRecMem(arr, target - arr[i], i-1, dp);
    
        dp[i][target] = pick or notpick;
    }
    return dp[i][target];
   
}
bool subsetSumToKMem(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    int state = solveRecMem(arr, k, n-1, dp);
    
    if (state) return true;
    return false;
}

//method Bottom UP Space Optimization 
//time complexity : O(target * n) where n is the size of gieven array 
//space complexity : O(target)
bool subsetSumToK(int n, int k, vector<int> &arr) {
 
    vector<bool> prev(k+1, false);

    //base cases 
    prev[0] = true;
    prev[arr[0]] = true;
    
    for(int i = 1; i < n; i++){
        
        vector<bool> curr(k+1, false);
        curr[0] = true;
        
        for(int target = 1; target < k+1; target++){
            
            bool notpick = prev[target];
            
            bool pick = false; 
            if(arr[i] <= target)  pick = prev[target - arr[i]];
  
            curr[target] = pick or notpick;
        }
        prev = curr;
    }
    
    return prev[k];
}

//method Bottom UP DP
//time complexity : O(target * n), Where n is the size of gieven array 
//space complexity : O(target * n) for dp array 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    //base case
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    
    for(int i = 1; i < n; i++){
        
        for(int j = 1; j < k+1; j++){
            
            bool notpick = dp[i-1][j];
            
            bool pick = false; 
            if(arr[i] <= j)  pick = dp[i-1][j - arr[i]];
  
            dp[i][j] = pick or notpick;
        }
    }
    
    return dp[n-1][k];
}