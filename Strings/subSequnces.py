def makeSubseq(input, o, res):
    if len(input) == 0:
        res.append(o)
        return

    # include character
    makeSubseq(input[1:], o + input[0], res)

    # exclude character
    makeSubseq(input[1:], o, res)

# method--> pick and not pick
# O(2^N)

if __name__ == "__main__":
    string = input()
    output =""
    result = []
    makeSubseq(string, output, result)
    print("{} - {}".format(result, len(result)))