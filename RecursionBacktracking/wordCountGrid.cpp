/* Problem Statement
Given an m x n grid of characters board and a string word, for a given word, count the total number of word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once. 

Time complexity:O(n * m * 4^n)
Space Complexity:4^n

where n is the length of given word
*/

#include <iostream>
#include <vector>
using namespace std;

 bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, vector<int> &dx, vector<int> &dy){
        
        //base case
        if(k == word.length())
            return 1;
        
        //rec case
        //invalid cases
        if (i >= board.size() or i < 0 or j < 0 or j >= board[0].size() or board[i][j] != word[k])
            //board[i][j] != word[k] if char matches then this is not visited if not macthes either it is not a correct sequence or already visited in word search
         return 0;
         
        int cnt = 0;
        char temp = board[i][j];
        board[i][j] = '$';//help as a visted array too
        
       for(int dir = 0; dir < 4; dir++)//converted 4 if statement in signle 1 using combinations of 4 directions same goes for rate in maze problem too
            cnt += dfs(board, word, i+dx[dir], j+dy[dir], k+1, dx, dy);
            
        board[i][j] = temp; //backtrack step
        
        return cnt;
}
int wordCountDFS(vector< vector<char>> &board, string word){
    
    int count = 0;
    //4 poosible direction combination 
    vector <int> dx{1, 0, 0, -1};
    vector <int> dy{0, -1, 1, 0};
    
    for(int i = 0 ; i < board.size(); i++){
            
        for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0])
                    count += dfs(board, word, i, j, 0, dx, dy);
        }
    }
    return count;
    
}
int main() {
	//code
	int m, n;
	cin >> m >> n;
	vector< vector<char>> board(m, vector<char>(n));
	
	for (int i = 0; i < m; i++){
	    
	    for (int j=0; j < n; j++){
	        cin >> board[i][j] ;
	    }
	}
	
	string word ;
	cin >> word;
	
	cout << wordCountDFS(board, word); 
	
	return 0;
}