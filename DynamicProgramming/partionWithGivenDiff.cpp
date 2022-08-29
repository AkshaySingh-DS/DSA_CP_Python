/* https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628 */

#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

/*
    Logic boils it target sum: 
    we know this, s1-s2 = d ..i) , s(total)= s1+s2 => s1 = total - s2 .. ii), 
    from eq i) and  ii) 
    
    total - s2  - s2 = d => 2s2 = total - d => s2 = (total - d)/2
    so if we found s2 as (total-d)/ 2 then s1 should be bounded with this.
    hence count s2 will give the answer.
    
    NOTE: Here total - d must be divisible by 2 else no such subsets s2 arfe possible i.e. no such s1-s2 = d found. 
    */


//Method Memoization : Idea using the concept of target sum count
//Time Complexity : O(N * totalsum(arr))
//Space Complexity : Rec Aux Stack O(N) + dp array  O(N * totalsum(arr))

int solveMem(vector<int> &nums, int target, int i,  vector<vector<int>> &dp){
        
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
   
int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(int i = 0; i < n; i++)   total += arr[i];   
    
    if (total < d or (total - d) % 2 == 1)    return 0; //no such s1 -s2 is there
    int s2 = (total - d)/2;
    
    vector<vector<int>> dp(n, vector<int>(s2+1, -1));
    return solveMem(arr, s2, n-1, dp);   
}

//Method Tabulation : Idea using the concept of target sum count
//Time Complexity : O(N * totalsum(arr))
//Space Complexity : dp array  O(N * totalsum(arr))

int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(int i = 0; i < n; i++)   total += arr[i];   
    
    if (total < d or (total - d) % 2 == 1)    return 0; //no such s1 -s2 is there
    int s2 = (total - d)/2;
    
    vector<vector<int>> dp(n, vector<int>(s2+1, 0));
    //base cases
    for (int i = 0; i < n ; i++) dp[i][0] = 1;
    if (arr[0] <= s2) dp[0][arr[0]] = 1;
    
    //for zeros 
    if(arr[0] == 0) dp[0][0] = 2;
    
    for(int i = 1; i < n ;i++){
        
        for(int j = 0; j < s2+1; j++){  //start from 0
            
            int notPick = dp[i-1][j];
        
            int pick = 0;
            if(arr[i] <= j) //skip zeros not include in subset
                pick = dp[i-1][j - arr[i]];
            
            dp[i][j] = (pick + notPick) % mod;        
        }
    } 
    return dp[n-1][s2];
    //return solveMem(arr, s2, n-1, dp);   
}