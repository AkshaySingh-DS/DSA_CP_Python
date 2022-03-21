/* 
Problem Statement : https://leetcode.com/problems/maximal-rectangle/
or 
https://practice.geeksforgeeks.org/problems/max-rectangle/1#

Time Complexity:  O(M*N)
Space Complexity: O(M)
*/

#include <iostream>
#include<stack>
#include <vector>
using namespace std;

class Solution {
private:
     vector<int> nextSmaller(int *arr , int n){
        
        stack <int> s;
        vector<int> ans(n);
        
        s.push(-1);
        
        for(int i = n-1; i >=0; i--){
            
            
            while(s.top() != -1 and arr[s.top()] >= arr[i]) s.pop();
            
            ans[i] = s.top();
            s.push(i);
                
        }
        
        return ans;
    }
    
     vector<int> prevSmaller(int *arr , int n){
        
        stack <int> s;
        vector<int> ans(n);
        
        s.push(-1);
        
        for(int i = 0; i < n ; i++ ){
            
            while(s.top() != -1 and arr[s.top()] >= arr[i]) s.pop();
            
            ans[i] = s.top();
            s.push(i);
            
        }
        
        return ans;
    }
    
    int largestAreaHist(int *arr, int n){
        
        vector <int> left(n);
        left = prevSmaller(arr, n);
        
        vector <int> right(n);
        right= nextSmaller(arr, n);
        
        int maxArea = INT_MIN;
        
        for(int i =0 ; i < n ;i++ ){
            
            if(right[i] == -1)
                right[i] = n;
            
            int area = arr[i] * (right[i] - left[i] -1);
            maxArea =  max(maxArea, area);
        }
        
        return maxArea;
    }
    
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        //convert it into first integers, since matrix is given as character 0's and 1's
        int n = matrix.size();
        int m = matrix[0].size();
        int arr[n][m];
        
        for (int i = 0 ;i < n; i++){
            for (int j = 0; j < m; j++){
                
                if(matrix[i][j] == '1')
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;     
            }
        }
        
       //compute area of first row
        int maxArea = largestAreaHist(arr[0], m);
        
        //now include the subsequent rows
        
        for (int  i = 1; i < n ; i++){
            
            for(int j = 0;  j < m ; j++){
                
                if(arr[i][j] != 0)
                    
                    arr[i][j] =  arr[i][j] + arr[i-1][j];
                
            }
            int area = largestAreaHist(arr[i], m);
            maxArea = max(maxArea, area);
        }

       return maxArea;  
    }
};