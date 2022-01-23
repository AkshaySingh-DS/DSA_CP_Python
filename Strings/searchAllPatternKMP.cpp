/* Problem Statement : https://practice.geeksforgeeks.org/problems/search-pattern0205/1#
Time Complexity :  O(N)
where N s the size of text
Assuming - > pattern_length <<<< text_length(N)

Space Complexity : O(N)
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
        vector <int> computeLPS(string pat){
            
            //preprocess the pattern text
            vector <int> lps(pat.length(), 0);
            int i = 1, j = 0;
            
            while (i < pat.length()){
                
                if(pat[i] == pat[j]) lps[i++] = ++j;
                
                else{
                    
                    if (j != 0) j = lps[j-1];
                    else lps[i++] = 0;
                }
            }
            
            return lps;
        }
        
    public:
vector <int> search(string pat, string txt)
        {
            //code hee.
            vector <int> ans;
            int cnt = 0 ;
            vector <int> lps = computeLPS(pat);
            
            int i = 0, j = 0 ;
            while(i < txt.length() and  j < pat.length()){
                
                
                if (txt[i] == pat[j]){
                    
                    i++;
                    j++;
                }
                
                //when pattern found 
                if (j == pat.length()){
                    
                    //adding one due to the index we have to start from "1" not with "0"
                    ans.push_back(i-j+1);
                    //we'll not start from the beggining take the help from lps array
                    j = lps[j-1];
                    
                }
                //i.e. pattern might have not matched so
                else if (txt[i] != pat[j] and i < txt.length()){
                    
                    if(j != 0) j = lps[j-1];
                    else i++;
                }
            }
            
            return ans;
        }
};
