"""
Problem Statement:https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?leftPanelTab=0

Time complexity : O(N*M)
Space COmplexity: O(N*M)
"""

def wavePrint(arr, nRows, mCols):
    
    # Write your code here.
    # Return a list of integers denoting the sine wave of the matrix
    ans = []
    for j in range(mCols):
        if j&1:
            for i in range(nRows-1, -1, -1):
                ans.append(arr[i][j])
        else:
            for i in range(nRows):
                ans.append(arr[i][j])
    return ans

"""
CPP Solution:
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    //Write your code here
    vector <int> ans;
    
    for(int j = 0 ; j < mCols; j++){
        
        //for j -> odd -> bottom to top 
        if(j & 1){
            for(int i = nRows -1 ; i >= 0 ; i-- )
                ans.push_back(arr[i][j]);
        }
        //for j -> even-> top to bottom 
        else{
            for(int i = 0 ; i < nRows ; i++ )
                ans.push_back(arr[i][j]);
        }  
    }  
    return ans;  
}
"""