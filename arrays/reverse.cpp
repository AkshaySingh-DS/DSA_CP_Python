#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// time complexity O(n/2) - > O(n) time.
void printArray(vector<int> ans){

    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;

 }

vector<int> reverse(vector<int> s){

    int left = 0, right = s.size() - 1;

    while (left < right){
        /* code */
        swap(s[left++], s[right--]);
    }
    return s;
}

int main(){

    vector<int> v;

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(0);
    v.push_back(8);

   cout << "Before Reverse : ";
   printArray(v);

   vector <int> ans = reverse(v);

   cout << "After Reverse : ";  
   printArray(ans);
    return 0;
}