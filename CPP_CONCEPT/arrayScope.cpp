#include <iostream>
using namespace std;

void printArray(int arr[], int size){

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

}

void updateArray(int arr[], int size){

    arr[1] = 100;
    cout << "going back to main" << endl;
}


int main(){

    int num [] = {1, 2, 3};

    printArray(num, 3);

    //calling update
    updateArray(num, 3);

    printArray(num, 3);

    return 0;
}