"""
Problem Statement:
https://www.codechef.com/problems/SNAKEEAT

TIME COMPLEXITY: O(N log N) + O(N)

"""
def maxSnakes(snakeslength, n, q):
    left = 0 ; right = n - 1
    ub = -1
    #logic
    while left <= right:

        mid = left + (right - left)//2
        
        if snakeslength[mid] < q:
            ub = mid
            left = mid + 1 

        else:
            right = mid - 1

    if ub == -1:
        return n
    
    count = n - (ub + 1)
    j = ub - 1
    lenghtSnkaes = snakeslength[ub]
    while ub > 0 and j >= 0:
        
        if lenghtSnkaes + 1 <= q:
            #keep on eating snakes
            lenghtSnkaes += 1
            j -= 1
        else:
            #now we get the snakes size == q move the upper bound and j
            count += 1
            ub = j
            j = ub -1
    
    return count 
    

def main():
    t = int(input())

    while t > 0:

        n, q = map(int, input().split())
        snakeslength = sorted(list(map(int, input().split())))
        for _ in range(q):
            k = int(input())
            print(maxSnakes(snakeslength, n, k))
        t -= 1

if __name__ == "__main__":
    main()