#include <iostream>
#include <vector>
using namespace std;

//Time complexity: O(n!)
//Space complexity: O(n) due to recusive calls

void printSolution(int arr[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

void solveNQueen(int arr[][100], int n, int i){
    //base case
    if (i == n){
        printSolution(arr, n);
        return;
    }
    
    //rec case
    for(int j = 0; j < n; j++){
        //whether the currenmt i,j is safe or not
        if(isSafeToPlace(arr, n, i, j)){
            arr[i][j] = 1;
            //if this possible then check for next place for other queen
            solveNQueen(arr, n, i + 1); 

            //if not possible to place then the configuration I have sat above was incorrect
            arr[i][j] = 0; //backtracking step(roll back)
        } 
    }
}

int main(){
    int n; 
    cin >> n;
    int arr[100][100] = {0};
    solveNQueen(arr, n, 0);
    return 0;
}