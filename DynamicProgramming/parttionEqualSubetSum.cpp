/* https://leetcode.com/problems/partition-equal-subset-sum/
 */
#include <iostream>
#include <vector>
using namespace std;

//Method Top down dp(Memoization) - Recursion
//time complexity : O(sum(arr))
//space complexity : O(n) where n is the number of elements

class Solution {
public:
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
    bool canPartition(vector<int>& nums) {   
        //edge case
        if(nums.size() == 1) return false;
        
        //get total sum to get target in order to find one subset 
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        if (totalSum & 1) return false; //if odd then not possible
         
        int K = totalSum/2;
        
        vector<vector<int>> dp(nums.size(), vector<int>(K+1, -1));
        int state = solveRecMem(nums, K, nums.size()-1, dp);

        if (state) return true;
        return false;
    }
};