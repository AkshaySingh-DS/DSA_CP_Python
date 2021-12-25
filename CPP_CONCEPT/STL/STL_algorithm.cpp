#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector <int> v;

    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(9);
    v.push_back(12);


    //find 6 in sorted order return 1 if present else 0 if not
    //time complexity : O(log N)
    cout << "is 6 element present ? " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "is -6 element present ? " << binary_search(v.begin(), v.end(), -6) << endl;
    
    //time complexity : O(log N)
    //get the lower bound index
    //elements -> 2, 5 ,6, 9, 12 for 10 it will be 12 i.e. index 4(just greater)
    cout << "lower bound " << lower_bound(v.begin(), v.end(), 10) - v.begin() << endl;

    //time complexity : O(log N)
    //elements -> 2, 5 ,6, 9, 12 for 6 it will be 6 i.e. index 2 (exceptional)
    cout << "lower bound " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;

     //time complexity : O(log N)
    //get the upper bound index
    //elements -> 2, 5 ,6, 9, 12 for 10 it will be 12 i.e. index 4(just greater)
    cout << "upper bound " << upper_bound(v.begin(), v.end(), 10) - v.begin() << endl;
   
    //time complexity : O(log N)
    //elements -> 2, 5 ,6, 9, 12 for 6 it will be 9 i.e. index 3(just greater)
    cout << "upper bound " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    //time complexity : O(1)
    int a = 4, b = 10;
    cout << max(a, b) << endl;

    cout << min(a, b) << endl;

    //time complexity : O(log 1)
    swap(a, b);
    cout << a << " " << b << endl;

    string abcd = "ABCDE";

    //time complexity : O(N)
    reverse(abcd.begin(), abcd.end());

    cout << abcd << endl;

    //insertion, Quick sort, heap sort
     //time complexity : O(N log N)
    sort(v.begin(), v.end());

    for (int val : v){

        cout << val << " ";
    }
    cout << endl;
    //time complexity : O(N)
    rotate(v.begin(), v.begin()+1, v.end());

    for (int val : v){

        cout << val << " ";
    }
    return 0;
}