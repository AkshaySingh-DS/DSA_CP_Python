/* Problem Statement : https://leetcode.com/problems/insertion-sort-list/
Time complexity : O(N^2)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//Time complexity : O(N^2) even in best case
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        //for empty list or only one node
        if (head == NULL or head -> next == NULL)
            return head;
        
        //pointer for sorted list i.e. head of the sorted list
        ListNode *helper = new ListNode(0); //dummy helper node
        
        ListNode *curr = head;
        ListNode *prev = helper;
        
        while(curr != NULL){
            
            //save next list, since this current we'll add with the sorted list
            ListNode *nextt = curr -> next;
            
            while(prev -> next != NULL and prev -> next -> val < curr -> val)
                prev = prev -> next;
            
            
            //now add the current node in sorted list
            curr -> next = prev -> next;
            prev -> next = curr;
            
            //now change the prev to helper and update the current for next node
            
            curr = nextt;
            
            //here every time after insertion we are starting from sorted head (which makes this code slow)
            prev = helper;           
        }
        
        //return the sorted list
        return helper -> next;
        
    }
};

//Time complexity : O(N) in best case
/*
ListNode* insertionSortList(ListNode* head) {
        
        //for empty list or only one node
        if (head == NULL or head -> next == NULL)
            return head;
        
        //pointer for sorted list i.e. head of the sorted list
        ListNode *helper = new ListNode(0); //dummy helper node
        
        ListNode *curr = head;
        ListNode *prev = helper;
        
        while(curr != NULL){
            
            //save next list, since this current we'll add with the sorted list
            ListNode *nextt = curr -> next;
            
            //by adding this line make sure that we can only change the prev to the sorted head iff prev next value is greater than current otherwise prev point will be the last node of sorted list (will make code faster in already sorted list case) 
            if(prev != NULL or prev -> next != NULL or prev -> next -> val > curr -> val) prev = helper;
            
            //find the location where we have to insert the current from prev(almost head of sorted list)
            while(prev -> next != NULL and prev -> next -> val < curr -> val)
                prev = prev -> next;
            
            
            //now add the current node in sorted list
            curr -> next = prev -> next;
            prev -> next = curr;
            
            //now change the prev to helper and update the current for next node
            
            curr = nextt;
            
            //here every time after insertion we are starting from sorted head (which makes this code slow)
           //prev = helper; (removing this line bcoz we'll not change prev after the currnt insertion we;ll whether it is really needed to change prev to helper)      
        }
        
        //return the sorted list
        return helper -> next;
        
    }
*/