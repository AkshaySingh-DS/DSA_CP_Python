"""
Problem Statement: 
given k strings concatinate them and then gives the single strings in a sorted manner.
"""
#NOTE: time complexity is O(N), where N is the len(s1) + len(s2) + len(s3)


def sortStringsUsingCountSort(stringsList):
    charCountArray = [0] * 256
    #logic
    for string in stringsList:
        for ch in string:
            charCountArray[ord(ch)] += 1

    for k in range(256):
        while charCountArray[k]:
            print(chr(k), end="")
            charCountArray[k] -= 1


def main():
    k = int(input())
    stringsList = [input() for _ in range(k)]
    sortStringsUsingCountSort(stringsList)


if __name__ == "__main__":
    main()