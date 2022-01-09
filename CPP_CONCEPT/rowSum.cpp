#include <iostream>
using namespace std;


void printArray(int arr[][4], int row, int col){

    for(int r = 0 ; r < row; r++){

        for(int c = 0 ; c < col; c++)
            cout << arr[r][c] << " " ;
        
        cout << endl;
    }
}

int largestSumRow(int arr[][4], int row, int col){

    int max = INT_MIN, idx;
    for(int r = 0; r < row; r++){
        int sum = 0;
        for(int c = 0; c < col; c++)
            sum += arr[r][c];
        
        if (max < sum){
            max = sum;
            idx = r;
        }
    }
    cout << max << endl;

    return idx;
}
int main(){
    int arr[3][4];

    //get elements
    for(int row = 0 ; row < 3; row++){

        for(int col = 0 ; col < 4; col++)
            cin >> arr[row][col];

    }
    //print array
    printArray(arr, 3, 4);
    cout << endl; 

    //print the row wise sum
    for(int r = 0; r < 3; r++){
        int sum = 0;
        for(int c = 0; c < 4; c++)
            sum += arr[r][c];
        
        cout << sum << endl;
    }
    cout << endl;
    //get the row whose sum is maximum with sum amount
    cout << largestSumRow(arr, 3, 4) << endl;
    return 0;
}