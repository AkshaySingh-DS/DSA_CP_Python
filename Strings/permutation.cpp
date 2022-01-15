/* problem statement : https://leetcode.com/problems/permutations/submissions/
time complexity : O(N!) */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void permuteSolve(vector <vector<int>> &ans, vector <int> nums, int idx){
        
        //base case
        if (idx == nums.size()){
             ans.push_back(nums);
            return;          
        }
           
        for(int j = idx; j < nums.size(); j++){
            
            //swap
            swap(nums[j], nums[idx]);
            
            //invoke recursive call
            permuteSolve(ans, nums, idx+1);
            
            //backtrack after call end to make abc -> bac, bca to make "abc" again, abc -> cba, cab
            swap(nums[j], nums[idx]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> ans;
        int idx = 0;
        permuteSolve(ans, nums, idx);
        return ans;
    }
};
