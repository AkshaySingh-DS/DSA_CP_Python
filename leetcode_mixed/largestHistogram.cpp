/* 
Problem Statement : https://leetcode.com/problems/largest-rectangle-in-histogram/

Approach1 :
step 1) for each bar cal the next smaller bar index at right and left indeex
step 2) Calculate area = bar_height * (right - left - 1) 
Time Complexity: O(N^2)
Space Complexity: O(1) not using auxilarry space

Approach2 : 
step 1) Calcluate next smaller for all.
step 2) Calcluate next previous smaller for all.
step 3) now, Calculate area of rectangle for each bar, and pick the largest from them.

Time Complexity:  O(N) in three passes
Space Complexity: O(N)
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    void getNextSmaller(vector <int> heights, vector <int> &arr, int size){
        
        stack <int> st;
        st.push(-1);
        
        //get the indices for all next smaller for each heihts bar
        
        for (int i = size - 1 ; i >= 0 ; i--){
            
            //stack(top) == -1 means no such next element is smaller for this current
            while(st.top() !=-1 and heights[st.top()] >= heights[i]) 
                st.pop();
            
            ////We are pushing indices instead of value  since we are more interested in indices that will help to calculate the ractangle width.
            arr[i] = st.top();
            st.push(i);    
        }
    }
    
    void getPrevSmaller(vector <int> heights, vector <int> &arr, int size){
        
        stack <int> st;
        st.push(-1);
        
        //get the indices for all next smaller for each heihts bar
        
        for (int i = 0 ; i < size ; i++){
            
            //stack(top) == -1 means no such prev element is smaller for this current 
            while(st.top() !=-1 and heights[st.top()] >= heights[i]) 
                st.pop();
            
            //We are pushing indices instead of value 
            arr[i] = st.top();
            st.push(i);     
        }
    }
    
    
public:
    int largestRectangleArea(vector<int>& heights){
        
        int size = heights.size();
        vector <int> right(size);
        vector <int> left(size);
        
        //get the indices for all next smaller
        getNextSmaller(heights, right, size);
        
        //get the indices for all prev smaller
        getPrevSmaller(heights, left, size);
        
        int maxArea = 0;
        
        for(int i = 0; i < size; i++){
            
            //calculate each bar Area
            int area = heights[i] * ((right[i] == -1 ? size : right[i]) - left[i] -1); //if right index '-1' i.e. right index we have to make 'size' that means for current bar no such element of its right is lesser.  
            maxArea = max(area, maxArea);
            
        }
        return maxArea;
    }
};
