#include <iostream>
using namespace std;

void printCharArray(char arr[], int size){

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl << 'PRINTING DONE' << endl; 
}
void printArray(int arr [], int size){
    for(int i = 0 ;i < size; i++){
        
        cout << arr[i] << " ";
    }
    cout << endl << "printing DONE" << endl;
}

int main(){

    //declaration

    int arr [10];

    //initializatin by hard coding

    int array[4] = {5, 7, 2, 1};
    printArray(array, 4);

    //initialized array with 0 inside all places
    int array2[5] = {0};
    printArray(array2, 4);

    //array size > array values, remaining values will be assigned to zero  
    int third[20] = {1, 2, 3, 4};
    printArray(third, 4);
    printArray(third, 20);

    //assign array by specific value
    int fourth [10] = {1}; //will not work
    printArray(fourth, 10);

    //solution of above
    int fifth [10] = {[0 ... 9] = 1}; 
    printArray(fifth, 10);

    //array for differet data type
    char chararray[5] = {'A', 'b', 'c','d', 'e'};
    int size = sizeof(chararray)/sizeof(char);
    cout << size << endl;
    printCharArray(chararray, size);
    return 0;
}