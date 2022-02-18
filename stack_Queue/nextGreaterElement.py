"""
Problem Statement :https://www.codingninjas.com/codestudio/problems/next-greater-element_799354?leftPanelTab=3
Time Complexity: O(N)
Space Complexity: O(N), sice we are using stack
"""

def nextGreaterElement(arr, size):
    stack = [0]
    output =[0] * size
    for next in range(1, size):
        while stack and arr[next] > arr[stack[-1]]:
            output[stack[-1]] = arr[next]
            stack.pop()

        stack.append(next)

    # element for which no greater element exist
    while stack:
        output[stack[-1]] = -1
        stack.pop()

    print(output)

if __name__ == "__main__":
    array = [13, 7, 6, 12]
    #array = [6, 8, 0, 1, 3]
    print(array)
    nextGreaterElement(array, len(array))

"""
CPP SOLUTION :
#include <iostream>
#include<stack>
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n) {
    //no need to take extra memory will update the given vector 
    stack <int> st;
    for (int i = n-1 ; i >= 0 ; i--){
        
        //get the current elemnt and save it
        int curr = arr[i];
        
        //keep popping the lement from stack untill stack is not empty or stack(top) > current 
        while (!st.empty() and st.top() <= curr)
            st.pop();
        
        //either got the next greater in stack or stack might empty
        st.empty() ? arr[i] = -1 : arr[i] = st.top();
        st.push(curr);
    }
    
    return arr;
}
"""

