"""
problem statement:
CODEFORCES: Very Easy task
The executive secretory of Olympiads made their statement, and printed in one copy.
now they need to make n more copies before the start of the olympiad. They have two copiers at disposal.
one takes x secs and another one takes y secs in coppying the text.(It is allwed to use two copiers at same time also)
task is to find the minimum time they need to make n copies of the statement.

Input:
test_cases t, n, x, y
2
4 1 1 
5 1 2

Output:
3
4
"""
def good(c1, c2, n, time):
    #no of copies made in this time frame is that time frame is big enough?
    #removing one extra copy from since only one copy available at t = 0, so we'll use copier who is fast 
    #and discard the copy create by copier who was little slower
    """Aprroch-1 for n copies
    if c1 < c2:
        return (time // c1) + ((time // c2)-1) >= n
    else:
        return ((time // c1) - 1) + (time // c2) >= n
    """
    #approach - 2 make only n-1 copies add extra time by the copier1 who took less time to make one copy available to copier2 
    return (time//c1) + (time//c2) >= n-1

def minimumTimeByCopiers(n, c1, c2):
    left = 0; right = max(c1, c2) * n
    ans = 0
    #logic
    while left <= right:
        mid = (left + right) // 2
        boolean = good(c1, c2, n, mid)

        if boolean:
            #look for the much minimum time -> got to left
            ans = mid
            right = mid - 1
        else:
            #not feasible -> go to right
            left = mid + 1
    
    #Approach-1 return ans 
    return ans + min(c1, c2)
            

def main():
    testCases = int(input())
    for _ in range(testCases):
        n, c1, c2 = map(int, input().split())
        print(minimumTimeByCopiers(n, c1, c2))

if __name__ == "__main__":
    main()