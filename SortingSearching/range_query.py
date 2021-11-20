"""
problem statement:
given an array A with n integers.
task is to response the queries like "how many numbers" values are between L and R?

Input:
5 -> length of the array
10 1 10 3 4 -> array values
4 -> k number of queries
1 10 
2 9
3 4
2 2 -> K queries

Output:
5 2 2 0
"""
"""
Approach lower bound(k) < j | j is the smallest greater value from k
upper bound(k) > j | j | j is greatest smallest value from k

"""
def upperBound(arr, size, q):
    left = 0 ; right = size -1 
    #boundary case for say q = 1 from example array
    ans = - 1
    #logic
    while left <= right:
        mid = (left + right) // 2

        if arr[mid] < q:
            #looking for biggest smaller -> got the right for much bigger
            ans = mid
            left = mid + 1
        else:
            right = mid - 1

    return ans 

def lowerBound(arr, size, q):
    left = 0 ; right = size -1 
    #boundary case for say q = 10 from example array
    ans = size 
    #logic 
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] > q:
            #looking for the smallest bigger -> go to left for much smaller
            ans = mid
            right  = mid - 1  
        else:
            left = mid + 1
    
    return ans

def rangeQuerry(arr, size, q):
    lb = lowerBound(arr, size, q[1])
    ub = upperBound(arr, size, q[0])

    return lb - ub - 1


def main():
    size = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    kQueries = int(input())
    for _ in range(kQueries):
        q = tuple(map(int, input().split()))
        print(rangeQuerry(arr, size, q), end= " ")

    #invoke


if __name__ == "__main__":
    main()