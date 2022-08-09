/* Probelem Statement: You are a professional robber planning to rob houses along a street. Each house 
has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the 
first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

problem link: https://leetcode.com/problems/house-robber-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //time complexity: O(N)
    //space complexity: O(N)
    int maxAmountRob(vector<int> &nums){
        
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;
        
        for(int i = 1; i < n; i++){
            
            int pick = nums[i] + prev2;
            
            prev2 = prev1;
            
            prev1 = max(pick, prev1);
            
        }
        
        return prev1;
      
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        //edge case don't confused with two houses they won't be circular anyhow (they are not node) :P
        if(n == 1) return nums[0];
        
        //devide array in two parts by seprating first and last element.
        
        vector <int> nums1(nums.begin() + 1, nums.end());
        vector <int> nums2(nums.begin(), nums.end()-1);
        
        /* for(int i = 0; i < n; i++){
            
            if(i != 0)  nums2.push_back(nums[i]); //contains last house  not first house
            if(i != n-1)  nums1.push_back(nums[i]); //contains first house not last house
        } */

       //return the max of houses which includes first house, and the houses which includes last house  
       return max (maxAmountRob(nums1), maxAmountRob(nums2));
        
    }
};
