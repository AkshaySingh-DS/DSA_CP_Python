/* Probelem Statement:The problem is to print all the possible paths from top left to bottom right of a mXn 
matrix with the constraints that from each cell you can either move only to right or down.

GFG LINK: https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/

Time Complexity:O(2^m*n)
Space Complexity:O(n)

*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector <vector<int>> &board, int m, int n, int i, int j, vector <int> &path){

    //base case
    if (i == m-1 and j == n-1){
        
        for(int k = 0; k < path.size(); k++) cout << path[k] << " ";
        cout << endl;
        return;
    }
    //rec case
    //down move
    if(i+1 < m){
        path.push_back(board[i+1][j]);
        dfs(board, m, n, i+1, j, path);
        path.pop_back();
    }
    //right move
    if(j+1 < n){
        path.push_back(board[i][j+1]);
        dfs(board, m, n, i, j+1, path);
        path.pop_back();
    }
}
void allPaths(vector <vector<int>> &board, int m, int n){

    vector <int> path;
    path.push_back(board[0][0]);
    dfs(board, m, n, 0, 0, path);
}
int main() {
	int m, n;
	cin >> m >> n;
	vector< vector<int>> board(m, vector<int>(n));
	
	for (int i = 0; i < m; i++){
	    
	    for (int j=0; j < n; j++){
	        cin >> board[i][j] ;
	    }
	}
    allPaths(board, m, n);
	return 0;
}