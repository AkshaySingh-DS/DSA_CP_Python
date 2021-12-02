"""Problem Statement :
https://www.spoj.com/problems/PRATA/

Time complexity: Let R max rank then time taken by R to make all Prata -> k and numbers of cooks let say c, then c * log(k) would be the time

IMPORTANT ARTICLE TO TAKE COMPLEX INPUTS IN PYTHON IN CP: 
https://levelup.gitconnected.com/basic-input-and-output-techniques-used-in-competitive-programming-5be5622b4525
"""
def good(currentmintime, p, cooks, ranks):
    #prata made initially
    pratcnt = 0

    #logic to be good mid 
    for i in range(cooks):
        t = 0; j = 1
        while True:
            t = t + (j * ranks[i])
            j += 1
            if currentmintime < t:
                break
            pratcnt += 1

    #return True if they are able to make  prta >= p
    return pratcnt >= p

def minTimeforPrata(p, cooks, ranks, maxRanks):
    left = 0 ; ans = 0

    #calculate search space by getting the cook who is taking max time.
    right = 0
    cnt = 0; i = 1
    while cnt < p:
        right = right + (i * maxRanks)
        cnt += 1
        i += 1

    #binary search logic to reduce time

    while left <= right:
        mid = (left + right)//2

        if good(mid, p, cooks, ranks):
            #if mid time is good enough then minimize it further
            ans = mid
            right = mid - 1
        else:
            left = mid + 1

    return ans
        
def main():
    test_cases = int(input())
    for _ in range(test_cases):
        p = int(input())
        cooks, *ranks = input().split()
        cooks = int(cooks)
        ranks = list(map(int, ranks))
        maxRanks = max(ranks)
        print(minTimeforPrata(p, cooks, ranks, maxRanks))

if __name__ == "__main__":
    main()