def linearSearch(arr, size, i, Key):
    if i == size:
        return -1
    elif arr[i] == Key:
        return i
    else:
        return linearSearch(arr, size, i+1, Key)

if __name__ == "__main__":
    lis = [1,2,3,4,5,6,0,12,16,74,287,492740,362,2428,490,42694,13,84,8,284,4714,849714,78216,48124,38139,339,833,8393,3108,3183,644,9527904,4792,482,5985]
    key = 482
    item_index = linearSearch(lis, len(lis), 0, key)
    print('item not found') if item_index == -1 else print(f"item present at {item_index} index")
    key = 18
    item_index = linearSearch(lis, len(lis), 0, key)
    print('item not found') if item_index == -1 else print(f"item present at {item_index} index")


# NOTE: Favourite Logical Question
