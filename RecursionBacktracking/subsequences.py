def allSubsequences(string, output, ans):
    if string == "":
        ans.append(output)
        return

    # pick character
    allSubsequences(string[1:], output + string[0], ans)

    # not pick character
    allSubsequences(string[1:], output, ans)

if __name__ == "__main__":
    string = input()
    output = ""
    ans = []
    allSubsequences(string, output, ans)
    print(ans)