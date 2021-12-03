"""
""""""
CODEFORCES: Get Together
problem statement:
There are n people on straight line, they need to gather at one point. Each person knows his current position x(i),
and his speed v(i), help them to find out at what minimum time they can gather at a point.

Input:
n -> (1 <= n <= 10e5)
x1 v1-> (-1oe9 <= x(i) <= 10e9 ) and (1 <= v(i) <= 10e9 )) 
x2 v2
...
...
xn vn
example:
5
-1 5 
10 3
4 2
7 10
8 1

Output:
1.5 -> the minimum possible time it take to meet people at one point, (relative absolute error doesnt exceed 10e-6)
"""
def good(pos, speed, n, mid):
    #we'll try to find out the commom point where they are meeting at mid (current minimum) time

    ans_lower_lmt = - 10 ** (-9)
    ans_higher_lmt = 10 ** 9


    """
    Given a time period(mid -> current min time), and also given a point [pos] ans speed
    In order for mid to be a good, there will be  point x where everyone can reach witin time mid.

    CLAIM : "If somehow I can find position(s)", where people can go their homes to that point in time mid,
    then that means that point will be a meeting point. 
    """
    for i in range(n):

        #take ith person pos and speed

        ans_lower_lmt = max(ans_lower_lmt, pos[i] - (mid * speed[i]))
        ans_higher_lmt = min(ans_higher_lmt, pos[i] + (mid * speed[i]))

    #means meeting point exist since ovelapping reason is found in mid time
    if ans_higher_lmt >= ans_lower_lmt:
        return True
    
    return False


def getTogetherBinarySearch(pos, speed, n):
    #search space for time to be good
    #min time possible -> 0
    #considering worst case x1-> -10e9 and x2 -> 10e9 and speed is 1  hence max time will be 2 * 10e9.
    right = 2 * (10**9)
    left = 0 


    #logic -> fixed # of iteration or right - left 
    for _ in range(100):
        mid = (left + right) /2
        if good(pos, speed, n, mid):
            #minimize this time -> go to left
            right = mid 
        else:
            #not possible with mid -> maximize it
            left = mid 

    return right
            

def main():
    n = int(input())
    pos = []
    speed = []
    for _ in range(n):
        posi, speedi = map(int, input().split())

        pos.append(posi)
        speed.append(speedi)

    #invoke
    print(getTogetherBinarySearch(pos, speed, n))


if __name__ == "__main__":
    main()