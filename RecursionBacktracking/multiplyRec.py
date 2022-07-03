# time complexity is O(b)
def multiply(a, b):
    if b == 0:
        return 0
    elif (a>0 and b>0) or (a<0 and b>0):
        return a + multiply(a, b-1)
    elif (a > 0 and b < 0) or (b<0 and a<0):
        return -a + multiply(a, b+1)

if __name__== "__main__":
    print(multiply(-3, 4))


# NOTE: Logical Question