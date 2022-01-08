"""
Problem Statement: https://leetcode.com/problems/permutation-in-string/

Time complexity : 
Space Complexity :
"""
"""TIME COMPLEXITY : O(N + M), SPACE COMPLEXITY : O(1) ONLY 26TH CHARACTER WE ARE STORING THAT IS CONSTANT VALUE"""
class Solution(object):
    def checkInclusion(self, s1, s2):
        #character count in s1
        target = [0] * 26
        
        #time O(s1.length)
        for ch in s1:
            target[ord(ch) - ord('a')] += 1
            
        #first window traverse
        i = 0; len2 = len(s2) ; windSize = len(s1)
        wind = [0] * 26
        
        #time O(windowSize)
        while(i < len2 and i < windSize):
            wind[ord(s2[i]) - ord('a')] += 1
            i += 1
        
        #dont need to apply saperate loop for checkig in each element
        if wind == target:
            return True
        
        #rest windows element
        #time O(s2.length)
        while (i < len2):
            #add next character in window
            wind[ord(s2[i]) - ord('a')] += 1
            
            #remove first earlier character from window that was in window
            wind[ord(s2[i-windSize]) - ord('a')] -= 1
        
            #check window match
            if wind == target:
                return True
            
            #else go for next character if all values over i.e i > len(s2) return false
            i += 1
        
        return False


"""
CPP SOLUTION:

class Solution {
private:
    bool isEqual(vector<int> &vect1, vector<int> &vect2){
        
        for(int i = 0 ; i < 26 ; i++){
            
            if(vect1[i] != vect2[i])
                return false;
        }
        return true;
     }
    
public:
    bool checkInclusion(string s1, string s2) {
        
        vector <int> target(26, 0), windowCount(26, 0);
        //count characters in s1
        for(char ch : s1 )
            target[ch - 'a']++;
    
        int windowSize = s1.length(), i = 0;
        
        //create window 
        while(i < windowSize and i < s2.length()) // boundary case if s2.length < windowsize   
             windowCount[s2[i++] - 'a'] ++ ;
        
        //check if this first window already matched
        if (isEqual(target, windowCount))
            return true;
          
        //else expand window from right and shrink woindow from left untill match not found 
        while(i < s2.length()){
            
            //get the next character
            windowCount[s2[i] - 'a']++ ;
            
            //remove older character from window(left most)
            windowCount[s2[i - windowSize] - 'a']-- ;
            
            //check this window match
            if (isEqual(windowCount, target))
                return true;
            
            //else expand window untill i < s2.length or next window match
            i++;
        }      
        return false;
    }
};
"""