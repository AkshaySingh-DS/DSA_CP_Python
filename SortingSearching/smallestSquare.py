"""
problem statement:
There are n rectangles of the same size: w width, h height, it is required to find square of the smallest size
into which these recatangle can be packed. Recatangles can't be rotated.

Input:
2 3 10 -> (w, h, n)

Output:
9
"""

def good(w, h, n, sqLength):
    """rectanglesFromsbySquare = (sqLength // w) * (sqLength // h)
    if rectanglesFromsbySquare >= n:
        return True
    else:
        return False
    """
    return (sqLength // w) * (sqLength // h) >= n

def smallestSquare(width, height, n):

    #search space of bbinary search
    left = 0 ; right = n * max(width, height)
    ans = -1
    #logic
    while left <= right:
        mid = (left + right) //2
        boolean = good(width, height, n, mid)
        if boolean:
            #sqLength good enough to pack all the rectangles within a sqaure look for much smaller square
            ans = mid
            right = mid - 1
        else:
            left = mid + 1

    return ans
        
def main():
    width = int(input())
    height = int(input())
    noOfrectangles = int(input())
    #invoke
    print(smallestSquare(width, height, noOfrectangles))

if __name__ == "__main__":
    main()
