/*

Problem Statement : https://leetcode.com/problems/search-a-2d-matrix/
Time Complexity : O(log M*N), M, N number of rows and columns respectively
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //search space 
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = cols * rows - 1;
        
        while (left <= right){
            
            int mid = left + (right - left)/2;
            
            int i = mid/cols, j = mid % cols;
            if (matrix[i][j] == target)
                return true;
            
            else if(matrix[i][j] > target)
                //go to left
                right = mid - 1;
            else
                //go to right
                left = mid + 1;
        }
       return false;     
    }
};