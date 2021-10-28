def square_binary(n):
    s, e = 0, n
    ans = 0
    while s <= e:
        mid = (s+e)//2

        if mid * mid == n:
            return mid

        if mid * mid > n:
            e = mid-1

        elif mid * mid <= n:
            ans = mid
            s = mid+1

    return ans

def square(n, p):
    ans = square_binary(n)
    if ans * ans == n:
        return ans

    inc = 0.1
    for _ in range(p):

        while ans * ans <= n:
            ans += inc

        # very important step
        ans -= inc

        inc /= 10.0

    return round(ans, p)

def main():
    num = int(input())
    prec = int(input())
    print(square(num, prec))
    
if __name__ == "__main__":
    main()