"""
Problem statement: CODECHEF
https://www.codechef.com/problems/AMCS03

Time Complexity : O(log(base 3)k) * O(N)) 
"""

"""
Problem statement: CODECHEF
https://www.codechef.com/problems/AMCS03

Time Complexity : O(log(base 3)k) * O(N)) 
"""

import sys
def good(mid, speed, distance, ncoders):
    """ 
    -> Below code was faling due to the power calculation and lot of funcrion calling like main so remove functions/power will run the code
    mini = 10 ** 12
    maxi = 0.0

    for i in range(ncoders):
        #P(T) = speed * time + dis 
        mini = min(mini, speed[i] * mid + distance[i])
        maxi = max(maxi, speed[i] * mid + distance[i]) """

    maxi = max([speed[i] * mid + distance[i] for i in range(ncoders)])
    mini = min([speed[i] * mid + distance[i] for i in range(ncoders)])


    return maxi - mini


def minRaceTimefn_ternarySearch(speed, distance, ncoders, k):
    left = float(0) ; right = float(k)

    #for real number time
    for _ in range(100):
        mid1 = left + (right - left)/3
        mid2 = right - (right - left)/3

        fm1 = good(mid1, speed, distance, ncoders)
        fm2 = good(mid2, speed, distance, ncoders)

        if fm1 > fm2 :
            left = mid1
        else:
            right = mid2
    
    return good(left, speed, distance, ncoders)

def main():

    speed = []
    distance = []
    ncoders, k = map(int, sys.stdin.readline().strip().split())

    for _ in range(ncoders):
        s, d = list(map(int, sys.stdin.readline().strip().split()))
        speed.append(s)
        distance.append(d)

    print("{:.6f}".format(minRaceTimefn_ternarySearch(speed, distance, ncoders, k)))

if __name__ == "__main__":
    main()