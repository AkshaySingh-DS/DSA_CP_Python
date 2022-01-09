#include <iostream>
using namespace std;

bool isFound(int arr[][4], int row , int col, int key){

    for(int r = 0 ; r < row; r++){
        //linear serach in 2-d array
        for(int c = 0 ; c < col; c++){

            if (arr[r][c] == key)
                return true;
        }      
    }
    return false;
}

int main(){

    int arr[3][4];

    //get elements
    for(int row = 0 ; row < 3; row++){

        for(int col = 0 ; col < 4; col++)
            cin >> arr[row][col];

    }
    int target;
    cin >> target;
    cout << endl;
    cout << isFound(arr , 3, 4, target);
    cout << endl;
    return 0;
}