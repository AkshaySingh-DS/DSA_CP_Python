/* Problem Statement : https://leetcode.com/problems/palindrome-linked-list/
Time Complexity : 
Space Comlpexity :  
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//approach 1 Using an temp array store the all list values in the temp array.
//then check whether the array is palindrome.(using the array logic)
class Solution {
public:
    bool isPalindromeArray(vector <int> arr){
        
        int left = 0, right = arr.size() - 1;
        
        while (left < right){
            
            if (arr[left++] != arr[right--])
                return false;
            
        }
        return true;
        
        
    }
public:
    bool isPalindrome(ListNode* head) {
        
        vector <int> temp;
        
        ListNode *t = head;
        
        while (t != NULL){
            
            temp.push_back(t -> val);
            t = t -> next;
        }
        
        return isPalindromeArray(temp);
            
    }
};