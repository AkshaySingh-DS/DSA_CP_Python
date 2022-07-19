/* problem Statement: Write a program to solve a Sudoku puzzle by filling the empty cells.
leetcode: https://leetcode.com/problems/sudoku-solver/ 
GFG LINK: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
Time Complexity: O(9^(n*n)). 
Space Complexity: : O(n*n). 
*/


#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>> &ans, int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            cout << ans[i][j] << " ";
        
        cout << endl;
    }
}

bool isSafeToPlace(vector<vector<int>> &ans, int i, int j, int size, int no){

    //row and column check
    for(int k1 = 0; k1 < size; k1++){
        if(ans[k1][j] == no or ans[i][k1] == no) 
            return false;
    }
    //grid check
    int sx, sy;
    sx = i/3 * 3;
    sy = j/3 * 3;
    for(int k1 = sx; k1 < sx + 3; k1++){
        for(int k2 = sy; k2 < sy + 3; k2++){
            if(ans[k1][k2] == no) return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &ans, int i, int j, int size){

    //base case
    if(i == size){
        printBoard(ans, size);
        return true;
    } 

    //boundary case when a row gets completed
    if(j == size)
        return sudokuSolver(ans, i+1, 0, size);

    //if cell is already filled go for next one to fill 
    if(ans[i][j] != 0)
        return sudokuSolver(ans, i, j+1, size);

    //rec case
    for(int k = 0; k < 10; k++){
        if(isSafeToPlace(ans, i, j, size, k)){
            ans[i][j] = k;
            if (sudokuSolver(ans, i, j+1, size)) return true;
            ans[i][j] = 0;
        }
    }
    
    return false;
}
int main(){
    int n;
    cin >> n;
    vector <vector<int>> ans(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> ans[i][j];
    }

    sudokuSolver(ans, 0, 0 , n); 
    return 0;
}


//leetcode Solution
class Solution {
    
public:
    bool isSafeToPlace(char no, int r, int c, vector<vector<char>>& board, int i, int j){
        
        //row and col check 
        for(int k = 0; k < r; k++){
            if(board[i][k] == no or board[k][j] == no) return false;
        }
        
        //grid check
        int sx, sy;
        sx = i/3 * 3;
        sy = j/3 * 3;
        for(int k1 = sx; k1 < sx+3; k1++){
            
             for(int k2 = sy; k2 < sy+3; k2++){
                 
                 if(board[k1][k2] == no) return false;
             }
        }
        
        return true;    
    }
    
    bool sudokuHelper(int rows, int cols, vector<vector<char>>& board, int i, int j){
        
        //base case
        if (i == rows) return true;
        
        //boundary cases
        if(j == cols){
            
            return sudokuHelper(rows, cols, board, i+1, 0);
        }
        
        if(board[i][j] != '.'){
            //skip non empty cells
            return sudokuHelper(rows, cols, board, i, j+1);
        }
            
        
        //rec case
        for(char k = '1'; k <= '9'; k++){
            if (isSafeToPlace(k, rows, cols, board, i, j)){
                
                board[i][j] = k;
                if(sudokuHelper(rows, cols, board, i, j+1)) return true;
            }
        }
        
        board[i][j] = '.';
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        sudokuHelper(rows, cols, board, 0, 0);  
    }
}; 