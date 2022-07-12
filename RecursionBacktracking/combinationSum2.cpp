/* Probelem Statement:The problem is to print all the possible paths from top left to bottom right of a mXn 
matrix with the constraints that from each cell you can either move only to right or down.

GFG LINK: https://leetcode.com/problems/combination-sum-ii/

Time Complexity: 
Space Complexity:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(vector <int> &c, int i, int target, vector <int> &sol, vector <vector<int>> &ans, int totalSum){

    //base case
    if(target == totalSum){
        ans.push_back(sol);
        return;
    }
    
    //this statement comes after the above statement 
    if(target < totalSum or i >= c.size()) return;
        
    //rec case
    sol.push_back(c[i]);
    dfs(c, i+1, target, sol, ans, totalSum + c[i]);
    sol.pop_back(); //bactrack step
     
    //skip all duplicates for 2nd call to avoid duplicate combination    
    while(i+1 < c.size() and c[i] == c[i+1]) i++;
    dfs(c, i+1, target, sol, ans, totalSum);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector<int>> ans;
        vector <int> solSet;
        dfs(candidates, 0, target, solSet, ans, 0);

        return ans; 
        
    }
};

//gfg question sligtly different: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#
class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void dfs(vector <int> &c, int i, int target, vector <int> &sol, vector <vector<int>> &ans, int totalSum){

        //base case
        if(target == totalSum){
            ans.push_back(sol);
            return;
        }
        
        //this statement comes after the above statement 
        if(target < totalSum or i >= c.size()) return;
            
        //rec case
        sol.push_back(c[i]);
        dfs(c, i, target, sol, ans, totalSum + c[i]);//here duplicates are there but dont include the duplicate combinations
        sol.pop_back(); //bactrack step
         
        //skip all duplicates for 2nd call to avoid duplicate combination    
        while(i+1 < c.size() and c[i] == c[i+1]) i++;
        dfs(c, i+1, target, sol, ans, totalSum);
}
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        vector <vector<int>> ans;
        vector <int> solSet;
        dfs(A, 0, B, solSet, ans, 0);
        return ans; 
    }
};