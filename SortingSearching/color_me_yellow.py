"""
problem statement:
CODECHEFF : https://www.codechef.com/UAPRAC/problems/COLYLW

you need to color a floor plan is of 3 * n (3 rows, n columns)
you have the tiles of size 1*1 of different color. specually you have:
r -> tiles of color red
g -> tiles of color green
b-> tiles of color blue

What is the maximum number of columns you can color such that every 
column has at least 1 red and 1 blue ?

input:
T -> number of test cases
n, r, g, b -> no of tiles of recpective colors separated by space 

3
4 3 3 4
4 4 1 4
2 4 1 4 

Output:
3 
3 
2
"""
def good(r, b, g, col):
    #left tiles after filling red and blue is able to cover the rest tiles
    return (r - col) + (b - col) + g >= col 


def fillRGBTiles(n, r, g, b):
    left = 0 ; right = min(n, r, b)
    ans = 0
    #logic
    while left <= right:
        mid = (left + right) // 2
        boolean = good(r, g, b, mid)
        if boolean:
            #we nedd more columns -> go to right
            ans = mid
            left = mid + 1
        else:
            #we are run nning out of tiles -> go to left
            right = mid - 1

    return ans  

def main():
    t = int(input())
    for _ in range(t):
        n, r, g, b = map(int, input().split())
        print(fillRGBTiles(n, r, g, b))

if __name__ == "__main__":
    main()