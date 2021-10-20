"""
NOTE:Clue is simple rather than caculating number^2 linearly, we will use
nice approach like binary search
-> time complexity O(log N + prec) ==> O(log N) since precision is most probabaly upto 10 hence that is constant time

problem : calculate of square root upto given precison point
24
5
sqaure root of 24 is 4.89897
"""

def squareRoot(Num, prec):
    #search space
    left, right = 0, Num//2
    ans = 0

    #logic -> integer part -> Binary search on answer?
    while left <= right:
        mid = (left + right)//2
        if mid * mid <= Num:
            ans = mid
            left = mid + 1
        else:
            right = mid - 1


    #logic -> fractional part ?
    #time complexity for fracional part is O(prec * 9) -> O(prec) and precison is also upto 10 -> O(1)
    decimal = 0.1
    for _ in range(prec):

        #if 4.9 * 4.9 > 24 we found correct precison for 1st digit  i.e. 0.8 -> 4.8
        while ans * ans < Num:
            ans += decimal

        #make it 4.9 - 0.1 -> 4.8 and start doing same thing for 2nd digit
        ans -= decimal
        decimal /= 10

    return round(ans, prec)

def main():
    num = int(input())
    pre = int(input())
    sq_root = squareRoot(num,pre)
    print("sqaure root of {0} is {1}".format(num, sq_root))

if __name__ =="__main__":
    main()