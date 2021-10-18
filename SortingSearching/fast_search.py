"""
problem statement: 

-> you are given an array 'a' of 'n' intregers
your task is to response the queries like "how many values" are b/w 'i' and 'r'.

Example: 

i/p:
5 -> number of elements
10 1 10 3 4 - > elements
4 -> number of Query
1 10 -> q1
2 9 -> q2
3 4 -> q3 
2 2 -> q4

o/p:
5 2 2 0
"""
def upperBound(arr , n, key):
    l = 0
    r = n-1
    while l <= r:
        mid = (l + r)//2
        if arr[mid] <= key:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    
    return ans

def lowerBound(arr , n,  key):
    l = 0
    r = n-1

    while l <= r:
        mid = (l+r)//2
        if arr[mid] >= key:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1

    return ans
            

#overall time complexity O(n)
def fastSearchRange(arr , n, s , e):
    
    #lowerbound of s -> time complexity O(n)
    l = lowerBound(arr, n, s)

    #upperbound of e -> time complexity O(n)
    r = upperBound(arr, n, e)

    #number of element in b/w s and e, s and e are also inclusive
    return r - l + 1 
    

def main():
    #number of elements in array
    n = int(input())

    #array list
    l = sorted(list(map(int, input().split())))

    #number of query points
    q = int(input())
    for _ in range(q):

        #each query points
        s , e = map(int, input().split())
        print(fastSearchRange(l, n, s, e), end = " ")


if __name__ == "__main__":
    main()