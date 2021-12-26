// problem statement : https://leetcode.com/problems/rotate-array/#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(vector <int> &vect){

    for (int val : vect){

        cout << val << " ";
    }cout << endl;
}

//time complexity O(n) but space O(1)
void rotateArray(vector <int> &vect, int k){

    //if k > size -> boundary case.
    k = k % vect.size();

    reverse(vect.begin(), vect.end());
    reverse(vect.begin(), vect.begin()+k);
    reverse(vect.begin()+k, vect.end());

}
int main(){

    vector <int> v;
    int k;
    k = 10;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    cout << "before rotate : ";

    printArray(v);
    
    rotateArray(v, k);
    cout << "after rotate " << k % v.size() << " steps: ";

    printArray(v);

    return 0;
}

/*
time complexity O(1) but space O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int size = nums.size();
        vector <int> temp(size);
        
        if (size == k){
            
            return;
        }
        
        for(int i = 0; i < size; i++)    
            temp[(i + k) % size] = nums[i];
            //temp[loc] = nums[i];           
    
    
        //copy the temp vector into nums
            nums = temp;
        
    }
};

Python Solution:
class Solution(object):
    def rotate(self, nums, k):
        k = k % len(nums)    
        nums [:] = nums[-k:] + nums[:-k]
*/
