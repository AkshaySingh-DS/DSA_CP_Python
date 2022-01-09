#include <iostream>
using namespace std;

void printArray(int arr[][4], int row, int col){

    for (int r = 0 ; r < row; r++){

        for(int c = 0 ; c < col; c++)
            cout << arr[r][c] << " ";
        
        cout << endl;
    }
}

int main(){

    //get the element in 2-d array row wise
    /*   //initialize using following way statically
    int temp[3][4] = {1, 2, 3, 4, 5,  6,  7,  8,  9,  10,  11,  12};
    int temp2[3][4] = {{1, 2, 3, 4}, {5,  6,  7,  8},  {9,  10,  11,  12}}; */
    int arr[3][4];

    for (int row = 0 ; row < 3; row++){

        for(int col = 0 ; col < 4; col++)
            cin >> arr[row][col] ;
    }

    //print the array values 
    cout << "array values rows wise" << endl;
    printArray(arr, 3, 4);
    cout << endl;


    //grt the array values in column wise
    for (int col = 0 ; col < 4; col++){

        for(int row = 0 ; row < 3; row++)
            cin >> arr[row][col] ;
    }
    cout << endl;

    //print the array values 
    cout << "array values columns wise" << endl;
    printArray(arr, 3, 4);
    cout << endl;

    return 0;
}
//1 2 3 4 5 6 7 8 9 10 11 12
