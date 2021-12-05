
"""
Problem Statement : Codestdio
https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
"""
#contraints: inplace changes -> O(1) space
#time complexity : O(N) -> N number of elements
import sys
def sort_0_1_2(arr, size):

    #current pos of 0's and 2's in worst case 
    pos_0 = 0; pos_2 = size - 1
    current = 0

    while current <= pos_2:

        if arr[current] == 0:

            arr[pos_0], arr[current] = arr[current], arr[pos_0]
            pos_0 += 1
            current += 1

        elif arr[current] == 2:
            
            arr[pos_2], arr[current] = arr[current], arr[pos_2]
            pos_2 -= 1
            #current += 1, suppose 2 replaces the 0's then if current will move then 0's can't be placed in its right position
        
        #for 1's just bypass
        else:
            current += 1
        
        
"""
CPP SOLUTION:
void sort012(int *arr, int n)
{
  //   Write your code here
   int start = 0,i = 0, end = n-1;
   while(i <= end){
       if(arr[i] == 0){
           // swap
           swap(arr[i++], arr[start++]);
           
       }
       else if(arr[i]==2){
           swap(arr[i],arr[end--]);
       }
       else{
           i++;
       }
   }
}
"""

def printArray(arr):
    for i in arr:
        print(i, end = " ")
    
    print()

def main():
    t = int(sys.stdin.readline().strip())
    while t > 0:
        size = int(sys.stdin.readline().strip())
        arr = list(map(int, sys.stdin.readline().strip().split()))
        #inplace sort
        sort_0_1_2(arr, size)
        printArray(arr)
        t -= 1
    

if __name__ == "__main__":
    main()