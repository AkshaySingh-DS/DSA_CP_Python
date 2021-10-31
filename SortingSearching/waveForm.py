# Google, Amazon, GS etc(Leetcode challange)
"""
Problem Statement: The problem is we need to form the list 
which can form a wave form like up->down->up->down->up->down->up->down.
"""
#time complexity O(N/2) -> O(N) time
def WaveForm(arr):
    for i in range(1, len(arr), 2):
        if arr[i] > arr[i-1]:
            arr[i], arr[i-1] = arr[i-1], arr[i]
        if i != len(arr)-1:
            if arr[i] > arr[i+1]:
                 arr[i], arr[i+1] = arr[i+1], arr[i]

#time complexity -> O(N) time 
def Waveform2(arr, size):
    for i in range(1, size-1):
        if arr[i] > arr[i-1] and arr[i] < arr[i + 1]:
            #swap
            arr[i], arr[i+1] = arr[i+1], arr[i]

        if arr[i] < arr[i-1] and arr[i] > arr[i+1]:
            #swap
            arr[i], arr[i+1] = arr[i+1], arr[i]


#Method-3 we can also do same thing using sorting but it takes O(NlogN)+ O(N/2) more

def main():
    lis1 = [1, 2, -3, 4, 5, 6]
    lis2 = [-1, -2, -3, 10, 4, -4, -5, -6]

    #method-1
    print('method-1')
    WaveForm(lis1)
    print(lis1)
    WaveForm(lis2)
    print(lis2)

    #method-2
    print('method-2')
    lis1 = [1, 2, -3, 4, 5, 6]
    lis2 = [-1, -2, -3, 10, 4, -4, -5, -6]
    Waveform2(lis1, len(lis1))
    print(lis1)
    Waveform2(lis2, len(lis2))
    print(lis2)

if __name__ == "__main__":
    main()