/*
Problem Statement: https://leetcode.com/problems/spiral-matrix/
Time Complexity : O(N*M)
Space Complexity : O(N*M)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //ans vector
        vector <int> ans;
        
        //get number of elements
        int rows = matrix.size(), cols = matrix[0].size();
        int cnt = rows * cols;
        
        //initialize boundaries
        int firstRow = 0, lastRow = rows - 1;
        int firstCol = 0, lastCol = cols - 1;
        
        
        //logic for spiral printing
        while (cnt){
            //first row i.e col varies
            for(int i = firstCol; cnt > 0 and i <= lastCol; i++){
                
                ans.push_back(matrix[firstRow][i]);
                cnt--;
            }//update firstRow
            firstRow++;
            
            //last col i.e. row varies
            for(int i = firstRow; cnt > 0 and i <= lastRow; i++){
                
                ans.push_back(matrix[i][lastCol]);
                cnt--;
            }//update lastCol
            lastCol--;
            
            //last row i.e =. col varies
            for(int i = lastCol; cnt > 0 and i >= firstCol; i--){
                
                ans.push_back(matrix[lastRow][i]);
                cnt--;
            }//update lastRow
            lastRow--;
            
            //first col i.e. row varies
            for(int i = lastRow; cnt > 0 and i >= firstRow; i--){
                
                ans.push_back(matrix[i][firstCol]);
                cnt--;
            }//update firstCol
            firstCol++;     
        }
        
      return ans;  
    }
};



