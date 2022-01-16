/* Problem Satement : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Time Complexity : O(3^(N^2)) */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
    bool isMoveSafe(int x, int y, int n, vector<vector<int>> m, vector <vector<int>> visited){
        
        if (x >= 0 and x < n and y >= 0 and y < n and visited[x][y] == 0 and m[x][y] == 1)
            return true;
        
        return false;
    }
    
    private:
    void solveMaze(vector<vector<int>> m, int n, vector <vector<int>> visited, int x, int y, string path, vector <string> & ans){
        
        //base case
        if (x == n - 1 and y == n - 1){
            ans.push_back(path);
            return;
        }
        
        //recursive case
        visited[x][y] = 1;
        
        //Down
        if (isMoveSafe(x + 1, y, n, m, visited)){
            
            path.push_back('D');
            solveMaze(m, n, visited, x+1, y, path, ans);
            //backtrack
            path.pop_back();
        }
        
        //Left
          if (isMoveSafe(x, y-1, n, m, visited)){
            
            path.push_back('L');
           
            solveMaze(m, n, visited, x, y-1, path, ans);
            //backtrack
            path.pop_back();
        }
        //Right
         if (isMoveSafe(x, y+1, n, m, visited)){
            
            path.push_back('R');
            
            solveMaze(m, n, visited, x, y+1, path, ans);
            //backtrack
            path.pop_back();
        }
        //UP
         if (isMoveSafe(x-1, y, n, m, visited)){
            
            path.push_back('U');
            solveMaze(m, n, visited, x-1, y, path, ans);
            //backtrack
            path.pop_back();
        }
        
        //backtrack
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        //handle edge cases when source is already zero (all path blocks)
        vector <string> ans;
        if (m[0][0] == 0)
            return ans;
        vector <vector<int>> visited = m;
        int sourcex = 0, sourcey = 0;
        string path;
        //initializie visited matrix 
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < n ; j++)
               visited[i][j] = 0;
        }
        
        solveMaze(m, n, visited, sourcex, sourcey, path, ans);
        return ans;
    }
};