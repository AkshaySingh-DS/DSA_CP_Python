"""
Problem Statement : https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#
Time Complexity : O(M + N)
Where M, N are the length of given strings
"""

"""
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for 
every character of str1 to every character of str2 
best example:- 
1. xudzhi
   ftaicz
2. xudzhi  
   ftaick
3. xudzhif
   ftaickm
4. xudzhi - >not isomorphic
   ftafck
"""
def areIsomorphic(str1, str2):
    visited = [False] * 256
    hashmap = [-1] * 256
    lens1, lens2 = len(str1), len(str2)
    if lens1 != lens2:
        return 0

    for i in range(lens1):
        if hashmap[ord(str1[i])] == -1:

            if visited[ord(str2[i])] == True:
                return 0

            visited[ord(str2[i])] = True
            hashmap[ord(str1[i])] = str2[i]

        elif hashmap[ord(str1[i])] != str2[i]:
            return 0

    return 1

"""
CPP SOLUTION:
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if (str1.length() != str2.length())
            return false;
            
        char map[256]  = {false};
        bool visited[256] = {false};
        
        for(int i = 0; i < str2.length(); i++){
            
            //if str1 mapping not happend and str2 is already visited then false
            
            int index = int(str1[i]);
            if (map[index] == false){
                
                //if str2[i] is visited and character str1 os not mapped yet that means no isomorphic
                if (visited[str2[i]])
                    return false;
                
                //else map the str2 and make it visited as well
                visited[int(str2[i])] = true;
                map[index] = str2[i];

            }
            
            //if character str1 is already there, hence it must match with str2
            else if(map[index] != str2[i])
                return false;
        }
        
       return true; 
    }
};
"""

if __name__ == "__main__":
    string1 = input()
    string2 = input()
    print(areIsomorphic(string1, string2))