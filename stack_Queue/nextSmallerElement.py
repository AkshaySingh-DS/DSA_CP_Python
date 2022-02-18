"""
Problem Statement : https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581
Time Complexity: O(N)
Space Complexity: O(N)

Approach1 : Brute Force 
Chose current from left, 
Start from current , serach for next smaller from right of current
In worst case, will take (n-1) + (n-2) + (n-3) + ... + 1 => O(N^2) time.

Approach2 : 
Here stack is used to provide the next smaller element.
Using Stack, start from extreme right side from input array, if top of stack < current then we have top as next smaller for current, hence update the answer
if stack(top) >= element then just pop all such elements.
"""

def nextSmallerElement(arr, n):
    stack = [0]
    output = [0] * n

    # time complexity is O(N)
    for next in range(1, n):
        while stack and arr[next] < arr[stack[-1]]:
            output[stack[-1]] = arr[next]
            stack.pop()

        stack.append(next)

    while stack:
        output[stack[-1]] = -1
        stack.pop()

    return output


if __name__ == "__main__":
    arr = [13, 7, 6, 12]
    print(arr)
    size = len(arr)
    print(nextSmallerElement(arr, size))

"""
Much clean approach
CPP Solution:
#include <stack>
#include<iostream>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    int size = arr.size();
    
    //not needed to create extra space we'll return the same input vector
    //vector <int> ans(size);
    stack <int> st;
    st.push(-1);
    
    for (int i = size - 1; i >= 0; i--){
        
        int curr = arr[i];
        
        //keep poppong the elemnts from stack since they are bigger than current
        while(st.top() >= curr)
            st.pop();
            
        arr[i] = st.top();
        //this element can be the smaller for next, so push it
        st.push(curr);
    }
    return arr;
}
"""