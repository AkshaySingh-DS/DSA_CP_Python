/* Problem Statement : https://leetcode.com/problems/add-two-numbers/
Time complexity :O(max(M, N))
Space Complexity: O(max(N, M)) which is required to store the answer in new list

where M, N are the two list represented as a number
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){

        // handling edge case when both list have only 1 zero
        if ((l1->next == NULL and l1->val == 0) and (l2->next == NULL and l2->val == 0))
            return new ListNode(0);
        

        // intialize node and carry
        int carry = 0;
        ListNode *t1 = l1, *t2 = l2;

        // create dummy node of ans
        ListNode *dummyHead = new ListNode(-1);
        ListNode *t = dummyHead;

        // traverse each node and get the number
        while (t1 or t2 or carry){

            int value = 0 + carry;
            if (t1){
                value += t1->val;
                t1 = t1->next;
            }

            if (t2){
                value += t2->val;
                t2 = t2->next;
            }

            int sum = value % 10;
            carry = value / 10;

            //
            t ->next = new ListNode(sum);
            t = t -> next;
        }

        return dummyHead->next;
    }
};

//folllow up : If let say list are not reversed ?
//Approach: Hence first will reverse the sorted list then will apply the same logic as above 