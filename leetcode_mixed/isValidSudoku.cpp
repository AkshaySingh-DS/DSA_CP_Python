/* problem Statement: Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be 
validated according to the following rules:

https://leetcode.com/problems/valid-sudoku/

Time Complexity:O(N^2) where n is the size of n*n board.
Space Complexity:O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidCell(vector<vector<char>>& board, int i, int j, int nrows, int ncols, int no){
        //check row 
        for(int k = 0 ; k < ncols; k++){
            
            if(board[i][k] == no and k != j)
                return false;
        }
        
        //check col 
        for(int k = 0 ; k < nrows; k++){
            
            if(board[k][j] == no and k != i)
                return false;
        }
        
        //check grid
        int sx, sy;
        sx = i/3 * 3;
        sy = j/3 * 3;
        
        for(int k1 = sx ; k1 < sx+3; k1++){
            for(int k2 = sy ; k2 < sy+3; k2++){
                
                if(board[k1][k2] == no and (k1 != i and k2 != j)) return false;
            }
        }
        return true;         
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int nrows = board.size();
        int ncols = board[0].size();
        for(int i = 0; i < nrows; i++){
            for(int j = 0; j < ncols; j++){
                //skip empty cells
                if(board[i][j] != '.'){
                    bool isValid = isValidCell(board, i, j, nrows, ncols, board[i][j]);
                    if (isValid == false)
                    return false;
                }   
            }       
        } 
        return true;
    }
};