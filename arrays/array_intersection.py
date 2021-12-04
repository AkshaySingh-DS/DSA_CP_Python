
"""
Problem Statement : Codestdio
https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?leftPanelTab=1?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
TIME COMPLEXITY : O(max(M, N))
"""
import  sys
def findArrayIntersection(arr: list, n: int, brr: list, m: int):
    # Write your code here
    # Return a list containing all the common elements in arr and brr.
    intersec = []
    
    p = 0 ; q = 0
    flag = False
    
    while p < n and q < m:
        if arr[p]  == brr[q]:
            intersec.append(arr[p])
            p += 1 ; q += 1
            flag = True
        elif arr[p] < brr[q]:
            p += 1
        elif arr[p] > brr[q]:
            q += 1
            
    #if there at least one element is common 
    if flag:
        return intersec
   	
    return -1
    

def main():

    #will take fast input in console/terminal than input()
    t = int(sys.stdin.readline().rstrip())
    while t > 0:
        n, m = map(int, sys.stdin.readline().rstrip().split())
        arr = list(map(int, sys.stdin.readline().rstrip().split()))
        brr = list(map(int, sys.stdin.readline().rstrip().split()))
        print(findArrayIntersection(arr, n, brr, m))
        t -= 1

if __name__ == "__main__":
    main()

"""
CPP SOLUTION:

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    int p = 0, q = 0;
    vector<int> intersec;
    
    while (p < n && q < m){
        
        if(arr1[p] == arr2[q]){
            
            intersec.push_back(arr1[p]);
            p++;
            q++;
        }
          else if(arr1[p] > arr2[q]){
              
              q++;
          } 
          else{
              
              p++;
          }
    }
    
    return intersec;

"""