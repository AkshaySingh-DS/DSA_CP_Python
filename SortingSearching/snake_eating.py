"""
Problem Statement:
https://www.codechef.com/problems/SNAKEEAT

TIME COMPLEXITY: O(N log N) + O(log N) + O(log N)

"""
import sys

""" 
#method -1 TLE
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
    
    return count  """


#will give the prefix sum in O(1) thats the best idea 
def getPrefixSum(prefixSum, mid, M):

    #boundry case
    if mid == 0:
        return prefixSum[M]
    
    #cummulated sum from mid to upperBound 
    return prefixSum[M] - prefixSum[mid-1]

def maxSnakesSurvived(snakesLen, nsnakes, reqLen, prefixSum):
    #get all the snakes first that can be survived whose length >= reqLen

    left, right = 0, nsnakes - 1
    upperB = -1

    #below code can be solved used bisect module 
    while left <= right:

        mid = (left + right)//2

        if snakesLen[mid] < reqLen:
            upperB= mid
            left = mid + 1
        else:
            right = mid - 1

    #Boundary case all snakes len >= reqLen
    if upperB == -1:
        return n
    
    #else
    ans = n - (upperB + 1)

    #try to get all the left snakes from 0 to upperB that can make length reqLen by eating up each other

    """
    first we'll try, if all the snakes mid to upperBound(M) i.e. suffix that can be possible to eatup all left out snakes(0 to mid-1)
    if possible then we'll try to expand the suffix size i.e. will go the left else right i.e. reduce suffix size
    """ 

    left = 0; right = upperB
    snakes = 0

    while left <= right:


        mid = (left + right)//2

        #if this mid is good i.e. try to eatupu all mid left snakes from the mid+1 to right snakes (#snakes >= sigma(reqLen - snakesLen) from i = mid to)
        totalSnakes = reqLen * (upperB - mid + 1) - getPrefixSum(prefixSum, mid, upperB)

        
        if mid >= totalSnakes:
            #i.e. mid to upperBound suffix snakes are good enough
            #maximize suffix size i.e go to left
            snakes = upperB - mid + 1
            right = mid - 1
        else:
            #diminish the suffiz size
            left = mid + 1
        
    return ans + snakes


t = int(sys.stdin.readline().strip())

while t > 0:

    n, q = map(int,  sys.stdin.readline().strip().split())
    snakeslength = sorted(list(map(int, sys.stdin.readline().strip().split())))

    prefixSum = [0] * n
    for i in range(n):
        prefixSum[i] = prefixSum[i - 1] + snakeslength[i]


    for _ in range(q):
        k = int(sys.stdin.readline().strip())
        print(maxSnakesSurvived(snakeslength, n, k, prefixSum))

    t -= 1