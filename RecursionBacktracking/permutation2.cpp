/* Probelem Statement:Given a collection of numbers, nums, that might contain duplicates, return all 
possible unique permutations in any order.

https://leetcode.com/problems/permutations-ii/

Time Complexity:
Space Complexity:

*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(vector<int> &nums, int i, vector<vector<int>> &ans, set <vector<int>> &s){
        //base case
        //permutation must not be there is set if there that means we already have combination
        if(i == nums.size() and s.find(nums) == s.end()){ 
            ans.push_back(nums);
            s.insert(nums);//update set as well 
            return;
        }

        //rec case
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            dfs(nums, i+1, ans, s);
            swap(nums[i], nums[j]);
            //check for duplicates if exists then skip them
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector<int>> ans;
        set <vector<int>> s;// we are using set to keep track the duplicates combinations
        dfs(nums, 0, ans, s);
        return ans;
    }
};