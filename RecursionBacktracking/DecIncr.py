# This method print Number from N to 1 in decreasing order
def dec(N):
    if N == 0:
        return None
    else:
        print(N)
        dec(N-1)
        
# This method print Number from 1 to N in Increasing order
def inc(N):
    if N == 0:
        return None
    else:
        inc(N-1)
        print(N)
if __name__ == "__main__":
    inc(3)
    print("-----"*5)
    dec(7)