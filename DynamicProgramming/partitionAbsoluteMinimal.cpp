/* 
https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
 */
#include <iostream>
#include <vector>

using namespace std;

//Method Memoization
//Time Complexity: O(n * total) 
//Space COmplexity: O(n) rec aux stack + O(n * total) 
int solveMem(vector<int>& arr, int n, int target, vector<vector<int>> &dp){
    
    //base case
    if(target == 0) return 1;
    if(n == 0) return target == arr[0];
    
    //rec case
    if(dp[n][target] == -1){
        bool notpick = solveMem(arr, n-1, target, dp);
        bool pick = false;
        if(arr[n] <= target)
            pick = solveMem(arr, n-1, target - arr[n], dp);
        
        dp[n][target] = notpick or pick;
    }
    
    return dp[n][target];   
}

int minSubsetSumDifference(vector<int>& arr, int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(total+1, -1));
    vector<bool>targetSum(total+1);
    
    for(int target = 0; target < total + 1; target++){
        targetSum[target] = solveMem(arr, n-1, target, dp);
    }
    
    //printArray(targetSum);
    int mini = 1e8;
    
    //no need to go upto total total/2 will work since after that s1 and s2 will interchange and abs diif will be same
    for(int target = 0; target < (total+1)/2 + 1; target++){
        
        if(targetSum[target] == true){
            int s2 = total - target;
            mini = min(abs(target - s2), mini);
        }           
    }
    return mini;    
}


//method fast tabulation (solve mem using this approach)
//time complexity: O(n * Toatal(sum(arr)))
//space complexity: for dp array  O(n * Toatal(sum(arr)))
int minSubsetSumDifference(vector<int>& arr, int n){
   
    int total = 0;
    for(int i = 0; i < n; i++)   total += arr[i];
  
    //tabulation code
    vector<vector<int>> dp(n, vector<int>(total+1, false));
    
    //base case
    for(int i = 0; i < n; i++)   dp[i][0] = true;
    dp[0][arr[0]] = true;
    //dp[i][j] -> is target j is possible by choosing the subarray from 0 to i from given arr
    //code start for tab approach
    for(int i = 1; i < n; i++){
        
        for(int j = 1; j < total+1; j++){
            
            bool notpick = dp[i-1][j];
            bool pick = false; 
            if(arr[i] <= j)  pick = dp[i-1][j - arr[i]];
            dp[i][j] = pick or notpick;
        }
    } 
    //last row of dp will give the first subset s1 if dp[n-1][target] == true i.e. target is one subset of set s1 hence s2 will be total - target and we want minimum abs(s1(target)-s2)
    int mini = 1e8;
    for(int target = 0; target < (total+1)/2 + 1; target++){
        
        if(dp[n-1][target] == 1){
            int s2 = total - target;
            mini = min(abs(target - s2), mini);
        }           
    }
    return mini;    
}