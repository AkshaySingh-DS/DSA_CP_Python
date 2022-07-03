def bubbleSort(lis, i):
    if i > len(lis)-2:
        return
    else:
        if lis[i] > lis[i+1]:
            lis[i],lis[i+1] = lis[i+1], lis[i]
        bubbleSort(lis, i+1)

def bubblePasses(lis, passes):
    if passes > len(lis)-1:
        return
    else:
        bubbleSort(lis, 0)
        bubblePasses(lis, passes + 1)

#ONLY SINGLE FUNCTION AS RECURSION
def BubbleSort_(lis, i, passes):
    if passes == len(lis):
        return
    elif i == len(lis)-1:
        i=0
        return BubbleSort_(lis, i, passes+1)
    elif lis[i] > lis[i+1]:
        lis[i], lis[i+1] = lis[i+1], lis[i]

    return BubbleSort_(lis, i+1, passes)

lis, passes = [10,1,2,0,4,5,9,11,7], 1
print(f'List before Sorting {lis}')
bubblePasses(lis, passes)
print(f'List After Sorting {lis}')
lis = [-10,1,-2,0,4,-5,9,-11,7,100]
print("--" * 5)
print(f'List before Sorting {lis}')
bubblePasses(lis, passes)
print(f'List After Sorting {lis}')
lis2 = [-10,2,1,0,4,3,5]
print('--' * 5)

BubbleSort_(lis2, 0, passes)
print(lis2)


# NOTE: Favourite Logical Question