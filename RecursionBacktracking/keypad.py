def keyPadOutput(input, size, output, i):
    # base case
    if i > size-1:
        print(output)
        return
    # current digit
    curr_digit = ord(input[i]) - ord('0')

    if curr_digit == 0 or curr_digit == 1:
        keyPadOutput(input, size, output, i+1)

    # recursive case
    for k in range(len(keypad[curr_digit])):
        keyPadOutput(input, size, output+keypad[curr_digit][k], i+1)


if __name__ == "__main__":
    keypad = ['','','ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
    input = input()
    output, i = "", 0
    keyPadOutput(input,len(input), output, i)