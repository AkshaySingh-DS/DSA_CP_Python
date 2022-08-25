/* https://leetcode.com/problems/pascals-triangle-ii/ */

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    //Bottom Up DP
    //time complexity : O(N^2) 
    //Space Complexity : O(N) where N is rowIndex
    vector<int> getRow(int rowIndex) {
        
        //base cases
        vector<int> curr(1, 1);
        if(rowIndex == 0) return curr;
        
        vector<int> prev(2, 1);
        if(rowIndex == 1) return prev;
        
        for(int i = 2; i < rowIndex + 1; i++){
            
            vector <int> curr(prev.size()+1, 1);
            
            for(int j = 1; j < curr.size()-1; j++){
                
                curr[j] = prev[j] + prev[j-1];
            }
            prev = curr;
        
        }
        
        return prev;
    }
};