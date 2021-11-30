"""
Problem Statement : 
https://www.spoj.com/problems/BOOKS1/

Time Complexity : O(M) + O(log(sum(pages))) + O(M)  
"""

def printPartition(pages, m, k, upperlimit):

    sum = 0
    cnt = 1
    output = []
    for i in range(m-1, -1, -1):
        #if k - cnt-1 (left subribers equal to number of books left then we'll stop since every scribers must get at least one book assign to him)
        if ((pages[i] + sum) > upperlimit) or (i == (k - cnt - 1)):
            #add pattern
            sum = 0
            cnt += 1
            #add separator
            output.append("/")
        
        sum += pages[i]
        output.append(pages[i])

    for val in output[::-1]:
       print(val, end=" ")



def good(mid, pages, m, k):
    scribers = 1
    sum = 0

    for i in range(m):
        if sum + pages[i] > mid:
            sum = 0
            scribers += 1

        if pages[i] > mid:
            #mid is too less 
            return False   
        
        sum += pages[i]

    #minimize it further
    return scribers <= k

def maxMinPagesPartition(pages, m, k):
    left = 0; right = sum(pages)
    ans = 0
    #logic
    while left <= right:

        mid = (left + right)//2

        if good(mid, pages, m, k):
            #minimize mid further -> current max sum
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    
    #get partition with minimum max-sum
    printPartition(pages, m, k, ans)


def main():
    n = int(input())
    #invoking
    for _ in range(n):
        m, k = map(int, input().split())
        pages = list(map(int, input().split()))
        maxMinPagesPartition(pages, m, k)

if __name__ == "__main__":
    main()