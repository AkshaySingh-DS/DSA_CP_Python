#include <iostream>
#include <vector>
using namespace std;


//time complexity O(N+M) 
//space complexity O(N) -> Try to reduce it further since nums1 has enough size 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector <int> ans;
        
        int i = 0, j = 0, k = 0;
        
        while(i < m and j < n){
            
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            
            else
                ans.push_back(nums2[j++]);
            
        }
        
        while(i < m)
            ans.push_back(nums1[i++]);

         while(j < n)
            ans.push_back(nums2[j++]);

        
        //copy the entire sorted ans vector in nums1
        
        for(int i = 0 ; i < m+n; i++)  
            nums1[i] = ans[i];
         
    }
};
//time complexity : O(N) sligly faster than the previous code, since omitting one loop. 
//space complexity O(1), i.e. not using any extra space.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int i = m - 1, j = n - 1;
        int k = m + n- 1;
        
        //try to sort in reverse order i.e. go for greater# instead smaller
        while(i >= 0 and j >= 0){
            
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            
            else
                nums1[k--] = nums2[j--];  
            
        }
        
        //if nums1 will be exausted else no need to do anything if nums2 will exausted i.e. nums1 data will be sorted.
        
         while(j >= 0)
              nums1[k--] = nums2[j--];
         
    }
};