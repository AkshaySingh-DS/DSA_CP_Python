/* Probelem Statement:Given an array of distinct integers candidates and a target integer target, return a 
list of all unique combinations of candidates where the chosen numbers sum to target. You may return the 
combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if 
the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations 
for the given input.

https://leetcode.com/problems/combination-sum/

Time Complexity: 
Space Complexity:

*/

class Solution {
public:
    void findSolutionSubset(int indx, vector<int> &candidates, vector <vector<int>> &ans, vector <int> subset, int sum, int target){

        //base case
        if (indx == candidates.size() or sum > target) return ;

        if (sum == target){

            ans.push_back(subset);
            return;
        }

        //rec case 
        subset.push_back(candidates[indx]);
        findSolutionSubset(indx, candidates, ans, subset, sum + candidates[i], target);
        subset.pop_back();
        findSolutionSubset(indx+1, candidates, ans, subset, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        vector <vector<int>> ans;
        vector <int> subset;
        int totalSum = 0;
        findSolutionSubset(0, candidates, ans, subset, totalSum, target);

        return ans;

    }
};