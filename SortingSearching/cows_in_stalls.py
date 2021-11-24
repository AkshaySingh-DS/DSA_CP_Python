"""
""""""
CODEFORCES: COWS IN STALL same as aggresive cows of SPOJ
Problem Statement:

Stalls are located on a staight line, your task is to arrange the cows to stalls so that the minimum distance 
b/w the cows is as large as possible.

Input:
n k -> (2 <= n <= 10e4, no of stalls), (2 <= k <= n, no of cows)
s1 s2 s3 ... sn -> (co-ordinate of stalls in ascending order-> 0 to 10e9)
example:
6 3
2 5 7 11 15 20

Output:
9 -> the largest possible minimum distance b/w two cows.

Time complexity:  O(n * log (max(stalls))) -> n number of stalls
"""

def good(stalls, n, k, min_distance):
    cowscnt = 1
    last_loc = stalls[0]

    for currentloc in range(1, n):
        if stalls[currentloc] - last_loc >= min_distance:
            last_loc = stalls[currentloc]
            cowscnt += 1
        
    if cowscnt == k:
        return True
    
    return False


def cowStalls_BinarySearch(stalls, n, k):
    left = 0; right = stalls[n-1] - stalls[0]
    ans = -1
    #logic
    while right >= left:
        mid = (left + right)//2
        if good(stalls, n, k, mid):
            ans = mid
            left = mid + 1
        else:
            right = mid - 1
        
    return ans


def main():
    n, k = map(int, input().split())
    stalls = list(map(int, input().split()))
    #invoke
    print(cowStalls_BinarySearch(stalls, n, k))


if __name__ == "__main__":
    main()