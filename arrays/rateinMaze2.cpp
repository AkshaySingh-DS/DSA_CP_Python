/*
Problem Statement : https://www.codechef.com/problems/BPHC03/
TIme Complexity : O(3^(N^2)) 
*/

#include <iostream>
#include <vector>
using namespace std;
bool isMoveSafe(int x, int y, int n, vector<vector<int>> m, vector <vector<int>> visited){
        
        if (x >= 0 and x < n and y >= 0 and y < n and visited[x][y] == 0 and m[x][y] == 0)
            return true;
        
        return false;
}

void solveMazeHelper(vector<vector<int>> m, int n, vector <vector<int>> visited, int x, int y, int & ans){
        
        //base case
        if (x == n - 1 and y == n - 1){
            ans++;
            return;
        }
        
        //recursive case
        visited[x][y] = 1;
        
        //Down
        if (isMoveSafe(x + 1, y, n, m, visited))
            solveMazeHelper(m, n, visited, x+1, y, ans);
    
        
        //Left
          if (isMoveSafe(x, y-1, n, m, visited))
            solveMazeHelper(m, n, visited, x, y-1, ans);

        //Right
         if (isMoveSafe(x, y+1, n, m, visited))
            solveMazeHelper(m, n, visited, x, y+1, ans);
  
        //UP
         if (isMoveSafe(x-1, y, n, m, visited))
            solveMazeHelper(m, n, visited, x-1, y, ans);
        
        //backtrack
        visited[x][y] = 0;
    }
int solveMazeProblem(){
    
    int size, ans = 0;
	cin >> size;
	
	vector <vector<int>> m(size, vector<int> (size));
	for(int i = 0; i < size; i++){
	    
	    for (int j = 0; j < size; j++){
	        
	        cin >> m[i][j];
	    }
	}
	
	
	//edge case source is blocked
	if (m[0][0] == 1)
	    return ans;
	
	vector <vector<int>> visited = m;
        int sourcex = 0, sourcey = 0;
        
    //initializie visited matrix 
    for(int i = 0; i < size; i++){
            
        for(int j = 0; j < size ; j++)
             visited[i][j] = 0;
    }
    
	solveMazeHelper(m, size, visited, 0, 0, ans);
	return ans;
}
int main() {
	// your code goes here
	cout << solveMazeProblem();
	return 0;
}
