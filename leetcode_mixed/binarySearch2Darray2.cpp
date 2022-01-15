/* problem statement: https://leetcode.com/problems/search-a-2d-matrix-ii/
Time complexity : O(M+N) */

//two pointer approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = 0;
        int rows = matrix.size();
        int col = matrix[0].size()-1;
        
        while (r < rows and col >= 0){
            
            int mid_val = matrix[r][col];
            
            if (mid_val == target)
                return true;
         
            else if (mid_val > target) 
                col--;
            
            else
                r++;
            
            // matrix[r][col] > target ? col-- : r++;    also work since if else only have oneline expression
        }
        
        return false;
    }
};