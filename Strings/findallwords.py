"""
Problem statement : 
find position of all words present in para.

Time Complexity : O(n * k)
Space Complexity: O(k), k number of words in para. 
"""

def find_All_Occurences(para, word):
    idx, word_pos = 0, []

    #idx -ve means no pattern found in para , there just come out
    while idx != -1:
        idx = para.lower().find(word.lower(), idx)
        if idx != -1:
            word_pos.append(idx)

            #increase the value of index for next word position
            idx += 1

    return word_pos


def main():
    para = "I liked the movie, acting in movie was great. And yes Endgame is one \
        the best Movie i have seen."
    word = 'movie'
    print(find_All_Occurences(para, word))


if __name__=="__main__":

    main()