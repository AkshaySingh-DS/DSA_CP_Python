#include <iostream>
using namespace std;
void printArray(int arr[], int size){

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

}

//time complexity O(N/2) - > O(N)
void reverse(int arr [], int size){

    //code
    int left = 0, right = size - 1;
    int temp;
    while (left < right){
       /*  temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp; 
        left++; right--; */
        swap(arr[left], arr[right]);
        left++; right--;
    } 
}

int main(){

    int arr [1000], size;

    cin >> size; 

    for(int  i=0 ; i< size; i++){

        cin >> arr[i];

    }
    cout << "Before reverse" << endl;
    printArray(arr, size);
    reverse(arr, size);

    cout << "After reverse" << endl;
    printArray(arr, size);
    return 0;
}