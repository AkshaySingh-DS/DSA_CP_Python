/* https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532 
https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/


#include <iostream>
#include <vector>
using namespace std;

//Using plaine recursion -> gives TLE
//Time complexity : O(n^sum)
//Space Complexity ; O(n) rec stack
int solveRec(vector<int> &nums, int target, int i){
    //base case
    if(target == 0) return 1;
    
    if(i == 0 ){
        if(target == nums[0]) return 1;
        return 0;
    }
    //rec case
    int notPick = solveRec(nums, target, i-1);
    
    int pick = 0;
    pick = solveRec(nums, target - nums[i], i-1);
    
    return pick + notPick;
      
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return solveRec(num, tar, n-1);
    
}

//Using memoization 
//not working when input consists number of zero in an array
//time complexity: O(n * Target), Space Complexity: Rec Aux Stack O(n) + O(N * Target) for DP array
int solveMem(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
    //base case
    if(target == 0) return 1;
    if(i == 0 ){
        return target == nums[0];
    }
    
    //rec case
    if(dp[i][target] == -1){
        int notPick = solveMem(nums, target, i-1, dp);
    
        int pick = 0;
        if(nums[i] <= target and nums[i] != 0)
            pick = solveMem(nums, target - nums[i], i-1, dp);
        
        dp[i][target] = pick + notPick;;
        
    }  
    return dp[i][target];      
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1)); 
    return solveMem(num, tar, n-1, dp);
}

//Improvement over memnoization which will work for zeros inputs too
int solveMem(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
    //base case
    if(target == 0) return 1;
    if(i == 0 )
        return target == nums[0]; 
    //rec case
    if(dp[i][target] == -1){
        int notPick = solveMem(nums, target, i-1, dp);
    
        int pick = 0;
        if(nums[i] <= target and nums[i] != 0) //skip zeros not include in subset
            pick = solveMem(nums, target - nums[i], i-1, dp);
        
        dp[i][target] = pick + notPick;;
        
    }  
    return dp[i][target];      
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    int countZeros = 0;
    
    for(int i= 0; i < n; i++){
       if(num[i] == 0) countZeros++;
    }
    //formula -> we have two choices for a zero(either include in a subset or not), hence k number of zeros we have 2^k choices so answer will be -> All subset not including zeros * 2^k, where k is the nuber of zeros
    vector<vector<int>> dp(n, vector<int>(tar+1, -1)); 
    return pow(2, countZeros) * solveMem(num, tar, n-1, dp);
}

//Improvement in first memoization approach
#define mod 1000000007
int solveMem(int nums[], int target, int i,  vector<vector<int>> &dp){
	    
        //base case
        if(i == 0){
            if(target == 0 and target == nums[0]) return 2; //we have two choices here either pick 0 or not
            if(target == 0 || target == nums[0]) return 1; //we have one choice in this case
            return 0; //for other cases 
        }
        
        //rec case
        if(dp[i][target] == -1){
            int notPick = solveMem(nums, target, i-1, dp);
        
            int pick = 0;
            if(nums[i] <= target) //skip zeros not include in subset
                pick = solveMem(nums, target - nums[i], i-1, dp);
            
            dp[i][target] = (pick + notPick) % mod;
        
        }  
        return dp[i][target];      
    }
    
int perfectSum(int arr[], int n, int sum){
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solveMem(arr, sum, n-1, dp);
}

//Time complexity : O(n * target)
//Space Complexity ; O(n) Aux Rec stack + O(n * target) for dp array
//below can be optimized further it terms of space then space complexity would be O(target) + O(n)
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));

    //base cases
    for (int i = 0; i < n ; i++) dp[i][0] = 1;
    if (num[0] <= tar) dp[0][num[0]] = 1; //else overflow issue
    
    //for zeros 
    if(num[0] == 0) dp[0][0] = 2;
    
    for(int i = 1; i < n ;i++){
        
        for(int j = 0; j < tar+1; j++){ //start from 0
            
            int notPick = dp[i-1][j];
        
            int pick = 0;
            if(num[i] <= j) //skip zeros not include in subset
                pick = dp[i-1][j - num[i]];
            
            dp[i][j] = (pick + notPick) % mod;        
        }
    } 
    return dp[n-1][tar];
}