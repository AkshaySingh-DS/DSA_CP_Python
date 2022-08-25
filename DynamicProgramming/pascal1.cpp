/* https://leetcode.com/problems/pascals-triangle/ */

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //bottom up dp with space optimization 
    //time complexity : O(N^2), space complexity : O(N)  
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        //base cases for n==1 or n==2
        vector<int> curr(1, 1);
        ans.push_back(curr);
        if(numRows == 1) return ans;
        
        vector<int> prev(2, 1);
        ans.push_back(prev);
        if(numRows == 2) return ans;
        
        //calculate Pascal triangle using logic from here
        for(int i = 2; i < numRows; i++){
            
            vector <int> curr(prev.size()+1, 1);
            
            for(int j = 1; j < curr.size()-1; j++){
                
                curr[j] = prev[j] + prev[j-1];
            }
            
            ans.push_back(curr);
            prev = curr;
        }
        
        return ans;        
    }
};