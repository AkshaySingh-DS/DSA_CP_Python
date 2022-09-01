/* https://leetcode.com/problems/target-sum/ */

class Solution {
public:
    int solveRec(vector<int>& nums, int i, int j, int target){
        
        //base case
        if(i == nums.size()-1){
            if(nums[i] + j == target and j - nums[i] == target) return 2; //we have two choices 
            if(nums[i] + j == target or j - nums[i] == target) return 1;
            
            return 0; // for rest cases
        }
        
        //rec case
        int pick_plus = solveRec(nums, i+1, j + nums[i], target);
        
        int pick_minus = solveRec(nums, i+1, j - nums[i], target);
        
        return pick_plus + pick_minus;
         
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solveRec(nums, 0, 0, target);
        
    }
};


/*
pyhon code due to choosing dictionary 
Memoization Top Down DP
Time Complexity: O(n * target)
Space Complexity: O(n) aux Rec stack space and nearly O(n * target) for dictionary

class Solution(object):
    def solveRec(self, nums, l, i, j, target, dp):
        #base case
        if i == l-1:
            if (nums[i] + j == target) and (j - nums[i] == target):
                return 2
            if(nums[i] + j == target or j - nums[i] == target):
                return 1
            
            return 0
        
        #rec case
        if (i, j) not in dp:
            pick_plus = self.solveRec(nums, l, i + 1, j + nums[i], target, dp)
            pick_minus = self.solveRec(nums, l, i + 1, j - nums[i], target, dp)

            dp[(i, j)] = pick_plus + pick_minus
        
        return dp[(i, j)]
    
    def findTargetSumWays(self, nums, target):
        
        dp = {} #reason for being using dictionary_map becoz j can be -ve so list will not work
        return self.solveRec(nums, len(nums), 0, 0, target, dp)     

*/

//time : O(n * target), space : O(n * target) + rec stack O(n)
//the problems boils down to count the subsets which makes the target sum s2 such that s2 = (s - target)/2
//logic : devide s into s1 and s2. s1 consist all positive numbers and s2 all negative, 
//now s1 - s2 = target we want hence can form the above logic and s1 + s2 = s(total sum)
class Solution {
public:
    int solveMem(vector<int>& nums, int i, int target, vector<vector<int>> &dp){

        //base case
        if(i == 0){
            if(nums[0] == 0 and target == 0) return 2;
            if(target == 0 or target == nums[0]) return 1;
            
            return 0;
        }
        
        //rec case
        if(dp[i][target] == -1){
            
            int notpick = solveMem(nums, i-1, target, dp);
        
            int pick = 0;
            if(nums[i] <= target){
                pick = solveMem(nums, i-1, target - nums[i], dp);
            }

            dp[i][target] = pick + notpick;
        }
        
        return dp[i][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total = 0;
        for(auto val : nums) total += val;
        if ((total - target) % 2 or total < target) return 0; //not possible any such combination
        
        int sum = (total - target)/2;
    
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        return solveMem(nums, nums.size()-1, sum, dp);     
    }
};