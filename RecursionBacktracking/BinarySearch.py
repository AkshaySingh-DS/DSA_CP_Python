def binarySearch(arr, low, high, Key):
    if low > high:
        return -1
    mid_index = (low + high)//2
    if arr[mid_index] < Key:
        return binarySearch(arr, mid_index+1, high, Key)
    elif arr[mid_index] > Key:
        return binarySearch(arr, low, mid_index-1, Key)
    else:
        return mid_index

if __name__ == "__main__":
    lis = [1,2,3,4,5,6,7,8,10,25,33,44,67,72,74,78,79,81,89,91,98,100,105,109,112,119,189,201,290]
    key_item = 112
    item_index = binarySearch(lis, 0, len(lis) - 1, key_item)
    print('Item not found') if item_index == -1 else print(f"Item found @ index {item_index}")
    key_item = 19
    item_index = binarySearch(lis, 0, len(lis) - 1, key_item)
    print('Item not found') if item_index == -1 else print(f"Item found @ index {item_index}")