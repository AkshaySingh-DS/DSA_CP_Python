/* Probelem Statement: You are a professional robber planning to rob houses along a 
street. Each house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into 
on the same night. Given an integer array nums representing the amount of money of each 
house, return the maximum amount of money you can rob tonight without alerting the
police.

problem link: https://leetcode.com/problems/house-robber/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //time complexity : O(N) max calls on an avg
    //space complexity: O(N) Rec Stack + O(N) -> O(N) using dp array
    int solveMem(vector<int>& nums, vector <int> &dp, int i){
        //base case
        if(i == 0) return nums[0];

        //edge case
        if(i < 0) return 0;

        //rec case
        if(dp[i] == -1){

            int pickHouse = nums[i] + solveMem(nums, dp, i-2);
            int notPickHouse = 0 + solveMem(nums, dp, i-1);
            dp[i] = max(pickHouse, notPickHouse);
            //dp[i] = max(nums[i] + solveMem(nums, dp, i-2), solveMem(nums, dp, i-1)); also work
        }

        return dp[i];
    }
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, -1);
        return solveMem(nums, dp, n-1);
    }

    //time complexity : O(n) max calls on an avg
    //space complexity: O(n) using dp array
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){

            int pick = nums[i];

            if(i > 1){
                pick += dp[i-2];
            }

            int notPick = 0 + dp[i-1];
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }

    //time complexity : O(n) max calls on an avg
    //space complexity: O(1) using tabulation with optimization
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int pick = nums[i] + prev2;
            //int notPick = 0 + prev1;
            prev2 = prev1;  
            prev1 = max(pick, prev1);
        }
        
        return prev1;
    }
};