"""
Problem Statement:
There is a long wire, and there are N nests of Birds, There are B birds (B <= N).
The Birds become angry when we put them into the nests. To put the birds from hurting each other you wants 
to assign birds to nests such that minimum distance between any two birds is as large as possible. 
What is the largest minimum distance?

example:

Input: 
number of nests: 5
number of Birds : 3
nests : [1, 2, 4, 8, 9]

Output:
3

"""

def canBirdPlace(nests, birds, sep):
    bcount = 1
    last_loc = nests[0]
    for i in range(1, len(nests)):
        current_loc = nests[i]

        if current_loc - last_loc >= sep:
            bcount += 1
            last_loc = current_loc

        if bcount == birds:
            return True

    return False


def angry_Birds(birds, nests):
    nests.sort()
    s, e = 0, nests[len(nests)-1]-nests[0]
    ans = -1
    while s <= e:
        mid = (s+e)//2

        bool = canBirdPlace(nests, birds, mid)

        if bool:
            s, ans = mid+1, mid
        else:
            e = mid-1

    return ans

def main():
    Birds = 3
    nestspos = [4, 2, 1, 9, 8]
    mindis = angry_Birds(Birds, nestspos)
    if mindis != -1:
        print(mindis)
    else:
        print('Not Possible to place all words')

if __name__ == "__main__":
    main()