/* Problem statement : https://leetcode.com/problems/subsets/
Time Complexity : 2^n, where n is the number of elements initailay for which we want to calculate 
poweset.

BEST DISSCUSSION : https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void powerSet(vector <vector<int>> &ans, vector<int> nums, vector <int> output, int idx){
        
        //base case
        if(idx >= nums.size()){
            
            ans.push_back(output);
            return;
        }
        
        //exclude
        powerSet(ans, nums, output, idx + 1);
        
        //include
        output.push_back(nums[idx]);
        powerSet(ans, nums, output, idx + 1);
        //dont need to backtrack since output is a local variable of function in case of string we have to back track(passed by refrence)
        //output.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> output;
        int idx = 0;
        
        powerSet(ans, nums, output, idx);
        return ans;
    }
};