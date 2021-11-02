"""
problem statement: https://www.spoj.com/problems/AGGRCOW/
problem is same as angry_birds
"""
#time complexity O(N log N) -> where N is the number of stalls

def iscowPlaced(stalls, n, c, mid):
    cnt = 1
    last_loc = stalls[0]
    for s in stalls:

        current_loc = s

        if current_loc - last_loc >= mid:
            last_loc = current_loc
            cnt += 1

        if cnt == c:
            return True
    
    return False
def agressive_Cows(stalls, n, c):
    l = 0 ; r = stalls[n-1] - stalls[0] # maximum minimum distance possible 'r'
    ans = -1
    #logic
    
    while l <= r:
        mid = (l + r) // 2
        bool_status = iscowPlaced(stalls, n, c, mid)

        if bool_status:
            l = mid + 1
            ans = mid
        else:
            r  = mid-1
    
    return ans

def main():
    #number of test cases
    t = int(input())
    for _ in range(t):
        #number of Stalls and number of Cows
        N, C = map(int, input().split())
        stalls = []
        #location of each Stalls
        for _ in range(N):
            stalls.append(int(input()))
        
        #invoke method
        stalls.sort()
        print(agressive_Cows(stalls, N, C))

if __name__ == "__main__":
    main()