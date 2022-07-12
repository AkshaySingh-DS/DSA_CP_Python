/* Probelem Statement:Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
https://leetcode.com/problems/permutations/

Time Complexity:
Space Complexity:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<int>& nums, int i, vector <vector<int>> &ans){

        //base case
        if(i == nums.size()){
            //got 1 permuation store the answer
            ans.push_back(nums);
            return;
        }

        //rec case

        for(int j = i; j < nums.size(); j++){

            swap(nums[i], nums[j]);

            dfs(nums, i+1, ans);
            //backtrack step 
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector <vector<int>> ans;
        int i = 0;

        dfs(nums, i, ans);

        return ans;
    }
};
