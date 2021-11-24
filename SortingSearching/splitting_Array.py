"""
CODEFORCES : Splitting An Array
problem statement:
Given an array of n positive integers. Your task is to divide it into k segments so that
the maximum sum on the segment is the minimum possible.

Input:
n k -> (1<=k<=n<= 10e9)
a1 a2 a3 ...an -> (1<=ai<=10e9) 
example:
10 4
1 3 2 4 10 8 4 2 5 3

Output:
12 -> the minimum possible maximum sum on segment

Time complexity -> (n* logsum(all))
"""
def good(arr, n, mid):
    segcnt = 0; maxsum = 0
    sum = 0
    for i in range(n):

        #if sum is exceeding to mid then it is a segment
        if sum + arr[i] > mid:
            segcnt += 1
            maxsum = max(sum, maxsum)
            sum = 0
        #else keep on updating sum untill we not found it more than mid
        sum += arr[i]

    #Boundary case like if after for loop once last element left mid = 14, cuurent-maxsum = 12,  current sum = 5+3 = 8, 5 3 5 -> 
    #5 + 3 + 5 = 13 -> then i need to update the mmaxsum
    if sum <= mid:
        maxsum = max(maxsum, sum)
        segcnt += 1
    
    return segcnt, maxsum


def splitArray_BinarySearch(arr, n, k):
    left = 0; right = sum(arr)

    while left <= right :
        mid = (left + right)//2
        segments, maxsum = good(arr, n, mid)
        if segments == k:
            #try to reduce this maxsum -> go to left
            ans = maxsum
            right = mid - 1
        elif segments < k:
            #mid is too big reduce it -> go to left again
            right = mid - 1
        elif segments > k:
            #mid is too less increase it -> go to right
            left = mid + 1
    
    return ans



def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    #invoke
    print(splitArray_BinarySearch(arr, n, k))
if __name__ == "__main__":
    main()
