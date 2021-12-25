#include <iostream>
using namespace std;

//time complexity O(M + N) , M size of arr1 and N soze of arr2
void printArray(int ans[], int size){

    for(int i = 0; i < size; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

 }
void mergeArray(int arr1 [], int size1, int arr2 [], int size2){

    int i = 0, k = 0, j = 0;
    int ans[1000];

    while(i < size1 and j < size2){

        if (arr1[i] < arr2[j])
            ans[k++] = arr1[i++];
        else
            ans[k++] = arr2[j++];

    }

    //if array 2 is exausted
    while(i < size1)
        ans[k++] = arr1[i++];

    //if array 1 is exausted
     while(j < size2)
        ans[k++] = arr2[j++];

    printArray(ans, k);

}
int main(){

    int arr2[5] = {1, 4, 5, 6, 7};
    int arr1[3] = {2, 3, 8};

    mergeArray(arr1, 3, arr2, 5);
    return 0;
}