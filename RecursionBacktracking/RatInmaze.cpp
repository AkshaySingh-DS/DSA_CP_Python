#include <iostream>
using namespace std;

/* NOTE: assuming path always exists except entry block 0, 0
time complexity -> O(4^(M*N))
space complexity -> O(M*N) for visited as well as depth of recxursion */

void possiblePathsToReach(int i, int j, int arr[][1000], int n, int m, string ans, int vis[][1000]){

    //base case
    if (i == n-1 and j == m-1){

        cout << ans << endl;
        
        return;
    } 
    
    //rec case
    //down move
    if(i+1 < n and arr[i+1][j] == 1 and vis[i+1][j] == 0){
        //visit this index
        vis[i][j] = 1; //don't visit this cell again in further calls not untill and unless this path is included   
        possiblePathsToReach(i+1, j, arr, n, m, ans + 'D', vis);
        vis[i][j] = 0;////bactrack step

    }

    //left move
    if(j-1 >= 0 and arr[i][j-1] == 1 and vis[i][j-1] == 0){
        //visit this index
        vis[i][j] = 1;
        possiblePathsToReach(i, j-1, arr, n, m, ans + 'L', vis);
        vis[i][j] = 0;////bactrack step
    }

    //right move
    if(j+1 < m and arr[i][j+1] == 1 and vis[i][j+1] == 0){
        //visit this index
        vis[i][j] = 1; 
        possiblePathsToReach(i, j+1, arr, n, m, ans + 'R', vis);
        vis[i][j] = 0; ////bactrack step
    }

    //up move
    if(i-1 >= 0 and arr[i-1][j] == 1 and vis[i-1][j] == 0){
        //visit this index
        vis[i][j] = 1;
        possiblePathsToReach(i-1, j, arr, n, m, ans + 'U', vis);
        vis[i][j] = 0; //bactrack step
    }
    
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
    string ans = "";
    if (maze[0][0] != 0)
        possiblePathsToReach(0, 0, maze, n, m, ans, visited);
    
    else cout << "Not possible since the entry is blocked" << endl;
    
    return 0;
}