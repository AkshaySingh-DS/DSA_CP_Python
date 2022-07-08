/* Probelem Statement:Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach 
the destination at (N - 1, N - 1). Count all possible paths that the rat can take to reach from source 
to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at 
a cell in the matrix represents that rat can be travel through it.

NOTE: Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat 
cannot move to any other cell. 

GFG LINK: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

*/

#include <iostream>
using namespace std;

int possiblePathsToReach(int i, int j, int arr[][1000], int n, int m, int vis[][1000]){

    //base case
    if (i == n-1 and j == m-1)
        return 1;
    
    //rec case
    int ways = 0;
    
    //down move
    if(i+1 < n and arr[i+1][j] == 1 and vis[i+1][j] == 0){
        //visit this index
        vis[i][j] = 1; //don't visit this cell again in further calls not untill and unless this path is included   
        ways += possiblePathsToReach(i+1, j, arr, n, m, vis);
        vis[i][j] = 0;////bactrack step

    }

    //left move
    if(j-1 >= 0 and arr[i][j-1] == 1 and vis[i][j-1] == 0){
        //visit this index
        vis[i][j] = 1;
        ways += possiblePathsToReach(i, j-1, arr, n, m, vis);
        vis[i][j] = 0;////bactrack step
    }

    //right move
    if(j+1 < m and arr[i][j+1] == 1 and vis[i][j+1] == 0){
        //visit this index
        vis[i][j] = 1; 
        ways += possiblePathsToReach(i, j+1, arr, n, m, vis);
        vis[i][j] = 0; ////bactrack step
    }

    //up move
    if(i-1 >= 0 and arr[i-1][j] == 1 and vis[i-1][j] == 0){
        //visit this index
        vis[i][j] = 1;
        ways += possiblePathsToReach(i-1, j, arr, n, m, vis);
        vis[i][j] = 0; //bactrack step
    }
    
    return ways;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    int maze[1000][1000];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> maze[i][j];
    }
    int visited [1000][1000]= {0};
    int total_ways;
    
    if (maze[0][0] != 0)
        total_ways = possiblePathsToReach(0, 0, maze, n, m, visited);
    
    else cout << "Not possible since the entry is blocked" << endl;
    
    cout << "Total paths to reach destination is: " << total_ways << endl;
    return 0;
}