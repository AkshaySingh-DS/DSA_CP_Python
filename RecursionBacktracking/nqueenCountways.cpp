#include <iostream>
#include <vector>
using namespace std;

//Time complexity: thetha(n!)
//Space complexity: O(n) due to recusive calls

bool isSafeToPlace(int arr[][100], int n, int i, int j){   
    //check column
    for (int k = 0; k < i; k++){

        if(arr[k][j]) return false;
    }
    //right diaogonal 
    int x = i-1, y = j+1;
    while(x >= 0 and y < n){

        if (arr[x--][y++]) return false;
    }

    //left diagonal
    x = i-1, y = j-1;
    while(x >= 0 and y >= 0){

        if (arr[x--][y--]) return false;
    }
    return true;
}

bool solveNQueen(int arr[][100], int n, int i){
    //base case
    if (i == n) return 1;
    //rec case
    int ways = 0;
    for(int j = 0; j < n; j++){
        if(isSafeToPlace(arr, n, i, j)){
            arr[i][j] = 1;
            ways += solveNQueen(arr, n, i + 1); 
            arr[i][j] = 0; //backtracking step(roll back)
        } 
    }
    return ways;
}

int main(){
    int n; 
    cin >> n;

    int arr[100][100] = {0};
    solveNQueen(arr, n, 0);
    return 0;
}