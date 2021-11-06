"""
Problem Statement: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can be many ways or permutations to do so. In each permutation, 
one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the 
maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Time complexity: O(N * log(sum(arr)))) -> N number of books and sum(arr)-> sum of all pages 
"""
def isAllocationPossible(books, m, mid):
    #logic to return True or False --> (if mid is smaller what we are looking for)
    sum  = 0
    stu_cnt = 1
    for pages in books:
        #boundary case-2 underfitting
        if pages >  mid:
            #means middle value is not largest 
            return False

        if sum + pages > mid:
            stu_cnt += 1
            #reset the current sum 
            sum = pages

            #boundary cases-1 underfitting
            if stu_cnt > m:
                #means chosen midile value is smaller
                return False 
        else:
            sum += pages
        
    return True
 

def binarySearch_bookAllocation(books, m):
    left = 0 ; right = sum(books)
    ans = -1
    #logic
    while left <= right:

        mid = (left + right) //2
        bool = isAllocationPossible(books, m, mid)
        if bool:
            ans = mid
            #move left for minimum pages
            right = mid - 1
        else:
            left = mid + 1
        
    return ans


def main():
    N = int(input())
    books = [int(p) for p in input().split()]
    m = int(input())
    print(binarySearch_bookAllocation(books, m))

if __name__ == "__main__":
    main()