/*
Time complexity : O(N)
Space Complexity : O(N) due to recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> vec, int size, int i){

    //base case
    if (i == size) return true; // work well if we have only 1 element in array

    // edge case for being an array unsorted
    if (vec[i-1] > vec[i]) return false; 

    //rec case (check for others elements if above is sorted)
    return isSorted(vec, size, i+1);
}

int main(){

    int size;
    vector<int> v;
    cin >> size;
    
    for(int i = 0; i < size ; i++){
        int num; 
        cin >> num;
        v.push_back(num);
    }

    //int size = sizeof(array)/sizeof(array[0]);
    //starting from 1th index since i-1 -> -1 in recursion

    cout << isSorted(v, size, 1) << endl;
    return 0;
}