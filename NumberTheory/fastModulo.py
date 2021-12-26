#time complexity to calc a^b % m is O(log N)
def powerModulo(a, b, m):
    pow_mod=1
    while b > 0:
        if b & 1:
            pow_mod = (pow_mod * a ) % m 
        a = (a * a) % m
        b = b>> 1 # reduce b or remove last bit
    return pow_mod

if __name__=="__main__":
    a=int(input())
    b=int(input())
    m=int(input())
    print('modulo power is', powerModulo(a, b, m))