"""
Problem Statement : search weather we have the pattern in the text or not.
Time Complexity : O(|N|+|M|), N (length of text, length of pattern)
"""

from Strings.longest_suffix_prefix import computeLPS

# time complexity O(N + M) -> O(N) N > M in ideal case.
#where N text length and m is the pattern length
def isMatchWithKMPalgorithm(text, pattern):
    lps = computeLPS(pattern)
    i = 0; j = 0
    textLenght = len(text)
    patternLength = len(pattern)
    
    #straight case
    if patternLength > textLenght:
        return False

    # logic
    while i < textLenght and j < patternLength:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        else:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1

    if j == patternLength:
        return True

    return False

"""
CPP Solution:
vector <int> computeLps(string s){
    
        int size = s.length();
	    int i = 1, j = 0;
	    
	    vector<int> lps(size, 0) ;
	    lps[0] = 0;
	    
	    while (i < size){
	        
	       if (s[i] == s[j])
	           lps[i++] = ++j;
	           
	       else{
	           if (j != 0) j = lps[j-1];
	           else lps[i++] = 0;
	           
	       }
	    }
	   
	   return lps; 
}

bool searchPatternKMP(string text, string pattern){
    
    vector <int > lps = computeLps(pattern);
    
    for(auto val : lps){
        
        cout << val << " ";
    }
    cout << endl;
    
    int i = 0, j = 0;
    
    while (i < text.length() and j < pattern.length()) {
        
        if (text[i] == pattern[j]){
            i++;
            j++;
        }
        
        else{
            
            if(j != 0 ) j = lps[j-1];
            else i++;
        }
        
    }
    if (j == pattern.length())
        return true;
        
    return false;
    
}
"""

if __name__ == "__main__":
    text = input()
    pattern = input()
    print(isMatchWithKMPalgorithm(text, pattern))