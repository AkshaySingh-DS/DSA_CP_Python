/* Problem Statement : https://leetcode.com/problems/word-search/
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once. 

Time complexity:O(n * m * 4^n)
Space Complexity:4^n

where n is the length of given word
*/


//below code is optimized in the sense of auxillary space as well as length wise
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        
        //base case
        if(k == word.length())
            return true;
        
        //rec case
        //invalid cases
        if (i >= board.size() or i < 0 or j < 0 or j >= board[0].size() or board[i][j] != word[k])
            //board[i][j] != word[k] if char matches then this is not visited if not macthes either it is not a correct sequence or already visited in word search
         return false;
         
        char temp = board[i][j];
        board[i][j] = '$';//help as a visited array
        
        bool status = (dfs(board, word, i+1, j, k+1)) or 
        (dfs(board, word, i, j-1, k+1)) or 
        (dfs(board, word, i, j+1, k+1)) or 
        (dfs(board, word, i-1, j, k+1));
        
        board[i][j] = temp; //backtrack step
        return status;
}
    bool exist(vector<vector<char>>& board, string word) {
        //vector <vector<int>> v(board.size(), vector<int> (board[0].size()));
        
        for(int i = 0 ; i < board.size(); i++){
            
            for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] =a= word[0] and dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};