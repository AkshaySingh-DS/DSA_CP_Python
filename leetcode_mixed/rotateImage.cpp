/*

Problem Statement : https://leetcode.com/problems/rotate-image/
Time Complexity : O(N^2)
Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

//Approach - 1
//using O(N^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //get the number of rows in 2D - vector
        int rows = matrix.size();

        //for square mareix/vector
        int cols = rows;
        
        //using extra space O(N^2)
        int arr[rows][cols];
        
        //logic
        
        for(int i = 0, j = cols-1; i < rows, j >= 0;  i++, j--){
            
            //convert first row into last column lokewise
            for(int m = 0, n = 0; m < cols, n < rows;  m++, n++)              
                arr[n][j] = matrix[i][m];
                
        }
       
        //update the inplace matrix
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0; j < cols; j++)
                matrix[i][j] = arr[i][j];
        }
    }
};

//Approach-2 using O(1) SPACE, two pointer 
void rotate(vector<vector<int>>& matrix) {
        
        
        //first transpose matrix inplace
        int rows = matrix.size();
        int columns = rows;
        for(int i = 0; i < rows ; i++){
            
            for(int j = i + 1 ; j < columns ; j++)
                //swap
                swap(matrix[i][j], matrix[j][i]);
    
        }
        //swap the first coilumn to last and keep on inwarding
        //two pointer approach
        
        int startCol = 0;
        int endCol = columns - 1;
        
        for(int startCol = 0, endCol = columns-1; startCol < endCol; startCol++, endCol-- ){
            
            for(int r = 0; r < rows ; r++)
                swap(matrix[r][startCol], matrix[r][endCol]);
        }
    }
/*
Python solution : 

*/

