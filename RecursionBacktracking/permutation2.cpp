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

/* 
Method2 : Without backtracking and call by value
Above backtracking solution is not optimal since it is taking unnecessary duplicates calls as well as 
searching the dupliocates in base case. We can reduce this as per below using call by value and without 
backtracking method. 
*/

class Solution {
public:
    //nums will be call by value
    void dfs(vector<int> nums, int i, vector<vector<int>> &ans){ 

        //base case
        if(i == nums.size()){ 
            ans.push_back(nums);
            return;
        }
        //rec case without backtracking
        for(int j = i; j < nums.size(); j++){
            
            if (i != j and nums[i] == nums[j]) continue;
                
                //for i == j this will work.
                swap(nums[i], nums[j]);
                dfs(nums, i+1, ans);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};
