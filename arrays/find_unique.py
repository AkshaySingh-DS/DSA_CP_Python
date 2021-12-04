"""
Problem Statement : Codestdio
https://www.codingninjas.com/codestudio/problems/find-unique_625159?leftPanelTab=0

TIME COMPLEXITY : O(N) 
using bitwise XOR
"""

import sys
from functools import reduce

def findUnique(arr, n) :
    #Your code goes here
    return reduce(lambda v1, v2 : v1 ^ v2, arr)
    

#Taking Input Using Fast I/O
def takeInput() :
    n = int(sys.stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    return arr, n


#main
t = int(sys.stdin.readline().rstrip())

while t > 0 :
    arr, n = takeInput()
    print(findUnique(arr, n))

    t -= 1

"""
CPP solution: 
int findUnique(int *arr, int size)
{
    //Write your code here
    int ans = arr[0];
    
    for(int i = 1; i < size ; i++){
        
        ans ^= arr[i];
    }
    return ans; 
}
"""