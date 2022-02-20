/* 
Problem Statement : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

Time complexity: O(N)
Space Complexity: O(N)

Follow up approach: O(1) space complexity::
*/

//approach - 1: using stack (optimized one), O(N) time.
//approach - 2: using simple approach two pass, check for each candidate, if row correspoding to that will be 0's and column correspoding would be 1's excpet digonal 
#include <iostream>
#include <stack>
using namespace std;
class Solution{

private:
    
    // knows(a, b ) means wheher a knoes b or not.
    bool isknows(vector<vector<int> >& M, int a, int b){
        
        if(M[a][b] == 1)
            return true;
            
        return false;
        
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        
        stack <int> st;
        
        //push all the canditate keys in stack first
        for(int i = 0 ; i<n ; i++)
            st.push(i);
            
        
        //now take top two candidate whether they knows each other or not if a knows b then discard A and push(b) in top of stack and vice versa
        while (st.size() != 1){ // !=1
            
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            //whether a knows b or not.
            if (isknows(M, a, b))
                st.push(b);
            else
                st.push(a);
        }
        
        //now check whether this potential candidate is really a celibrity or not
        int candidate = st.top();
        int zerocnt = 0;
        int onecnt = 0;

        //candidate must dont know any1 hence row for this will be zero
        for(int i = 0; i < n; i++){
            if(M[candidate][i] == 0)
                zerocnt ++;
        }
    
        if (zerocnt != n)
            return -1;
            
        //candidate must be known by every1 hence all values will be 1 except digonal 
        for(int i = 0; i < n ; i++){
            if(M[i][candidate] == 1)
                onecnt ++;
        }
         
        if (onecnt != n-1)
            return -1;
        
        return candidate;
    }
};
