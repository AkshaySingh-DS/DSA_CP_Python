# here we are considering a and b as +ve integer
def slowPow(a, b):
    if b == 0:
        return 1
    else:
        return (a * pow(a, b-1))

# time complexity O(b)

from math import ceil
def pow(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b%2 == 0:
        return (pow(a,b/2) * pow(a, b/2))
    elif b%2!= 0:
        return (a * pow(a, ceil(b/2)))

# time complexity O( log(b) ) time

# There are overlapping problem So think about it can this is DP problem
if __name__ == "__main__":
    print(pow(3, 4))
    print(pow(3, 4))


# Favourite Logical Question