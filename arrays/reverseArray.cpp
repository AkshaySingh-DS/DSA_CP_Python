/*
problem statement: https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1
Time complexity : O(N)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void printArray(vector<int> ans){

    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;

 }
 void reverseArray(vector<int> &s, int m){

    int left = m + 1, right = s.size() - 1;

    while (left < right){
        /* code */
        swap(s[left++], s[right--]);
    }
    
}
int main(){
    vector <int> v;
    int testcases, size, m;

    cin >> testcases;

    while (testcases --){
        cin >> size;
        cin >> m;
        for (int i = 0; i < size; i++){

            cin >> v[i];
        }

        reverseArray(v, m);
        printArray(v);
    }
    return 0;
}
