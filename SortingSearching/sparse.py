def update_midIdx(arr, s, e, mid):
    # linear search code for non empty string
    mid_left, mid_right = mid-1, mid+1
    while True :
        if mid_left >= s and mid_right <= e:
            if arr[mid_left] != "":
                return mid_left

            if arr[mid_right] != "":
                return mid_right

            mid_right += 1
            mid_left -= 1
        else:
            return -1
            #break


# recursive
def findKey(arr, s, e, key):
    # base case
    if s>e:
        return -1

    mid_idx = (s + e)//2
    if arr[mid_idx] == "":

    #update mid_idx
        mid_idx = update_midIdx(arr, s, e, mid_idx)

    # recursive case
    if arr[mid_idx] == key:
        return mid_idx
    elif arr[mid_idx] > key:
        return findKey(arr, s, mid_idx-1, key)
    else:
        return findKey(arr, mid_idx+1, e, key)

# non recursive
def searchKey(arr, s, e, key):

    while s <= e:
        mid = (s+e)//2
        if arr[mid]=="":
            #update middile
            mid = update_midIdx(arr, s, e, mid)

        if mid==-1:
            return -1 # not found
        if arr[mid] == key:
            return mid
        #left part
        elif arr[mid] > key:
            e = mid-1 #left part
        else:
            s = mid+1 #right part

    # not found
    else:
        return -1



if __name__=="__main__":
    arr = ['ai', '', 'bat', '', '', 'car', 'cat', 'kind', '', '', 'lion', '']
    #arr = ['ai', '', '', 'bat','','','car','cat','','','dog','']
    print(arr)
    key = input()
    ans = findKey(arr, 0, len(arr)-1, key)
    #ans = searchKey(arr, 0, len(arr)-1, key)
    if ans != -1:
        print(f"KEY found at {ans+1}")
    else:
        print(f'KEY not found')