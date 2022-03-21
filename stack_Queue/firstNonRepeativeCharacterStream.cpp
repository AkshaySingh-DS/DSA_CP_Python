/* 
Problem Statement :https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Using Approach-3
Time Complexity: O(N)
Space Complexity: O(1)
*/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


string FirstNonRepeating(string A){
		    
		    string ans;
		    queue <char> q; 
		    //front of the queue will help to represent the first non repeatetive character
		    unordered_map <char, int> count;
		    
		    for(auto ch : A){
		        
		        //count the character from stream and push into queue
		        count[ch]++;
		        
		        q.push(ch);
		        
		        //get the first non-repeatetive character from stream if exists
		        
		        while (!q.empty()){
		            
		            //if front of the character is repeative character
		            if (count[q.front()] > 1)
		                q.pop();
		                
		           else{
		               ans.push_back(q.front());
		               break;
		           }
		                
		        }
		        
		        //if no character found in queue means all chaacteras were repatetive hence add '#'
		        if(q.empty())
		            ans.push_back('#');
    
		    }
		    
            return ans;  
}
