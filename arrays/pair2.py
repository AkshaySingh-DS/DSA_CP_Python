# if data is already sortetd then hash-map don't needed
# time --> O(N) space (1)
def pairSorted(arr, sum):
    s, e = 0, len(arr)-1

    # logic
    while s < e:
        if arr[s] + arr[e] == sum \
                and arr[s] != arr[e]:
            return [arr[s], arr[e]]
        elif arr[s] + arr[e] > sum:
            e -= 1
        else:
            s += 1

    return [-1, -1]



if __name__ == "__main__":
    #data = [-8, -7, -6, 2, 3, 6, 10, 13, 15]
    sum = 4
    data = [1, 2, 6, 7, 8, 9]
    print(pairSorted(data, sum))
