/* https://leetcode.com/problems/arithmetic-slices/ */


#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:

    //Brute Force Solution -> O(N^2)
    bool isAP(vector<int>& nums, int i , int j){
        
        if(nums[i+1] - nums[i] == nums[j] - nums[j-1]) return true;
        
        return false;                  
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n-2; i++){ 
            for(int j = i + 2; j < n; j++){
                
                if(isAP(nums, i, j))   count ++;  
                else break;
            }
        }
        return count;
    }

class Solution1 {
public:
    //Bottom UP DP-> O(N), space O(N)
    bool isAP(vector<int>& nums, int i , int j){
        
        if(nums[i+1] - nums[i] == nums[j] - nums[j-1]) return true;
        
        return false;                  
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        int j = 0;
        for(int i = 0; i < n-2 and j < n; i++){
            
            j = i+2;
            
            while(j < n){
                
                if(isAP(nums, i, j)){
                    dp[j] = dp[j-1] + 1; 
                }
                else break;
                
                j++;
            }
        }
        
        int count = 0;
        for(auto val : dp){
            count += val;
        }
        return count;
    }
};

};