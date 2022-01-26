"""
Problem Statement : https://practice.geeksforgeeks.org/problems/8dcd25918295847b4ced54055eae35a8501181c1/1
Time Complexity : (|p|+|T|)
space COmplexity : O(|p|+|T|)

where P is pattern length and T is text length and text >> pattern 
"""

def computeZ(inpstring):
    inputLenghth = len(inpstring)
    z = [0] * inputLenghth

    # logic
    left, right = 0, 0
    for k in range(inputLenghth):
        if k > right:
            left, right = k, k
            
            while right < inputLenghth and inpstring[right] == inpstring[right - left]:
                right += 1
                
            z[k] = right - left
            right -= 1
            
        else:
            k1 = k - left
            if z[k1] + k <= right:
                z[k] = z[k1]

            else:
                left = k
                while right < inputLenghth and inpstring[right] == inpstring[right-left]:
                     right += 1
                     
            z[k] = right - left
            right -= 1
            
    return z



def zAlgorithm(text, pattern):
    textLength = len(text)
    patternLength = len(pattern)
    inp = pattern + '$' + text
    z = computeZ(inp)
    #print(z)
    ans = []
    # logic
    for i in range(textLength + patternLength + 1):
        if z[i] == patternLength:
            ans.append(i - patternLength - 1)

    return ans

if __name__ == "__main__":
    text = "aaabcxyzaaaabczaaczabbaaaaaaabc"
    pattern = "aaabc"
    print(zAlgorithm(text, pattern))

"""
Z-algorithm : Pattern Matching algorithm.
Z-function : Z(k) Core of the algorithm is the funtion z(k) = largest substring starting at k
which also a prefix.

example : a a b x a a y a a b
z-array : 0 1 0 0 2 1 0 3 1 0

i) We use the above information for patterm matching.
ii) Follow up How to make the above z-array efficiently.

Algorithm step: 
for e.g. pattern = a b c, text = x a b c a b z a a b c   

step i) create new string :- pattern + $(choose if not in pattern as well as in string) + text
a b c $ x a b c a b z a a b c  

step ii) calculate z - array
string : a b c $ x a b c a b z a a b c 
      z: 0 0 0 0 0 3 0 0 2 0 0 1 3 0 0 

step iii) Look for the index value in Z-array 
where pattern.length == z[index] -> pattern found in string

position of the pattern in actual text
index - (pattern.Length + 1)(means remove the character that added in text)

terminology : z-box (l, r) length till which it is matched with pattern.

CPP SOLUTION:
 private:
        vector <int> computeZ(string input, int size){
            
            vector <int> z(size);
            
            //define the boundary of z-box
            int left = 0, right = 0;
            
            //iterate over the input string
            for(int k = 1; k < size; k++){
                
                //there are two cases first if k present outside the z-box then r and l will be same
                //2nd if k inside the z box (which again cause two more cases)
                
                //case1: when k outside the z-box or we dont have z-box (length of z-box is zero)
                if (k > right){
                    
                    left = right = k;
                    
                    //create z-box, input[right - left] will give you the prefix character value
                    while(right < size and input[right] == input[right - left])
                        right++;
                    
                    //come out from the loop when data value will not match, update z for k, and also update right
                    z[k] = right - left;
                    right--;
                }
                 //case2 : when k is within the z-box
                else{
                    //case1 : when k is not violating the condition after copying the z value i.e not streching outside
                    //to z-boundary i.e less than r.
                    //copy all the value then
                    
                    int k1 = k - left;//(prefix matching)
                    
                    if(z[k1] + k <= right)
                        z[k] = z[k1]; //copy as it is
                    
                    //case2: when k violating the condition i.e. start computing in same way
                    else{
                        
                        left = k;
                        
                        while(right < size and input[right] == input[right-left])
                            right++;
                        
                        //update k
                        z[k] = right - left;
                        right--;
                    }
                }
            }
            
            return z;
            
        }
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string input = pat + '$' + txt;
            int size = input.length();
            vector <int> result = computeZ(input, size);
            vector <int> ans;
            
            //iterate over the ans array
            for(int i = 0; i < size ; i++){
                
                if (result[i] == pat.length())
                    ans.push_back(i - pat.length());
            }
    
            return ans;
        }
"""
