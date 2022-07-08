#include <iostream>
using namespace std;

bool ispossiblePathsToReach(int i, int j, int arr[][1000], int n, int m, int vis[][1000]){

    //base case
    if (i == n-1 and j == m-1)
        return true;
    
    //rec case  
    bool succeed = false;
    //down move
    if(i+1 < n and arr[i+1][j] == 1 and vis[i+1][j] == 0){
        //visit this index
        vis[i][j] = 1; //don't visit this cell again in further calls not untill and unless this path is included   
        succeed = ispossiblePathsToReach(i+1, j, arr, n, m, vis);
        if (succeed) return true;
        vis[i][j] = 0;////bactrack step

    }

    //left move
    
    if(j-1 >= 0 and arr[i][j-1] == 1 and vis[i][j-1] == 0){
        //visit this index
        vis[i][j] = 1;
        succeed = ispossiblePathsToReach(i, j-1, arr, n, m, vis);
        if (succeed) return true;
        vis[i][j] = 0;////bactrack step
    }

    //right move
    if(j+1 < m and arr[i][j+1] == 1 and vis[i][j+1] == 0){
        //visit this index
        vis[i][j] = 1; 
        succeed = ispossiblePathsToReach(i, j+1, arr, n, m, vis);
        if (succeed) return true;
        vis[i][j] = 0; ////bactrack step
    }

    //up move
    if(i-1 >= 0 and arr[i-1][j] == 1 and vis[i-1][j] == 0){
        //visit this index
        vis[i][j] = 1;
        succeed = ispossiblePathsToReach(i-1, j, arr, n, m, vis);
        if (succeed) return true;
        vis[i][j] = 0; //bactrack step
    }
    
    return succeed;
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
    if (maze[0][0] == 0) cout << 0;//edge case
    else cout << ispossiblePathsToReach(0, 0, maze, n, m, visited);
    
    return 0;
}