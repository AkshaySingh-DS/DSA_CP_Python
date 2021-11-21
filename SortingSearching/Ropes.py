"""
CONCEPT OF BINARY SEARCH ON REAL NUMBERS:

CODEFORCES : Ropes
problem statement:
There are n ropes, you need to cut k pieces of the "same length" from them.
Find the maximum length  of pieces you will get.

Input:
4 11 -> no of ropes, k
802 -> rope1
743 -> rope2
457 -> rope3
539 -> rope4

Output:
200.5 -> real no

The answer will be considered correct if the relative or absolute error doesnt exceed 10e-6
contraints:
1. n >= 1
2. 1 <= k <= 100000
3. 1 <= arr[i] <= 10**7

Time complexity -> O(log(n/eps) * n)
"""
def good(arr, n, k, x):
    total_pieces = 0
    for i in range(n):
        total_pieces += (arr[i]//x)
    
    #return True if no of pieces made by x is good enough i.e more than K
    return total_pieces >= k

def maxLenOfPieces(ropes, nOfRopes, k):
    left = 0 ; right = 10 ** 7

    #logic fixed no of iteration that at least should log(max ans / precison) -> 100 on most of the cases works
    for _ in range(100):

        mid = (left + right)/2
        if good(ropes, nOfRopes, k, mid):
            #maximize x | good enough to cut the k pieces -> go to right
            #not taking mid + 1 bcoz it will missed out lot of integers in b/w mid to mid + 1
            left = mid
        else:
            #minimize x | not good enough to cut k pieces -> go to the left
            #not taking mid -1 bcoz it will missed out lot of integers in b/w mid to mid - 1
            right = mid
    #with 100th iterations we can return either left or right bcoz they would be very close to each other
    #to get the answer upto 6 precision
    return "{0:.6f}".format(left)



def main():
    nOfRopes, k = map(int, input().split())
    ropes = []
    for _ in range(nOfRopes):
        ropes.append(int(input()))
    
    #invoke
    print(maxLenOfPieces(ropes, nOfRopes, k))

if __name__ == "__main__":
    main()