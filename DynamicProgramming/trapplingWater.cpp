/* https://leetcode.com/problems/trapping-rain-water/submissions/ 
*/

#include <iostream>
#include <vector>
using namespace std;

//Method brute force using two loops - O(N^2) where min(L, R) will take time O(N)
class Solution {
public:

    //Method using memoized prefix and suffix array
    //Can be optimized further using O(1) space -  two pointers approach

    int trap(vector<int>& height) {
        
        int n = height.size();
        
        //calculate prefix sum array
        vector<int> pref(n, 0);
        pref[0] = height[0];
        for(int i = 1 ; i < n; i++) pref[i] = max(pref[i-1], height[i]);
        
        //calculate suffix sum array
        vector<int> suff(n, 0);
        suff[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0; i--) suff[i] = max(suff[i+1], height[i]);
        
        //solve the water trapping
        int amtWater = 0;
        for(int i = 0; i < n; i++)   
            amtWater += (min(pref[i], suff[i]) - height[i]);
        
        return amtWater;
    }
};