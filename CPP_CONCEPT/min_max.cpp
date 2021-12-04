#include <iostream>
using namespace std;

int getMin(int arr[], int size){

    int mini = INT_MAX;

    for(int i = 0; i < size; i++){

   /*      if (min > arr[i]){

            min = arr[i];
        }*/

        mini = min(arr[i], mini);
    } 

    return mini;
}


int getMax(int arr[], int size){

    int maxi = INT_MIN;

    for(int i = 0; i < size; i++){


    /*     if (arr[i] > max){

            max = arr[i];
        }*/

         maxi = max(arr[i], maxi);
    } 

    return maxi;
}

int main(){

    int arr [10000]; //good thing 
    int size;
    //bad thing arr[size]
    cin >> size;

    for(int i = 0; i < size; i++){

        cin >> arr[i];
    }

    //cout << getMax(arr, size) << endl;
    cout << "min value is " << getMin(arr, size) << endl;
    cout << "max value is " << getMax(arr, size) << endl;

    return 0;
}