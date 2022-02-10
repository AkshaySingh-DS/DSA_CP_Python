/* Problem Statement : https://leetcode.com/problems/sort-list/submissions/
Time complexity : O(N log N)
space complexity : O(N log N ) since we are using recursion in merge procedure
it will be O(logn ) if we'll use iterative merge procedure

for better space complexity follow up O(1) approach:
https://leetcode.com/problems/sort-list/discuss/166324/c%2B%2B-and-java-legit-solution.-O(nlogn)-time-and-O(1)-space!-No-recursion!-With-detailed-explaination 
 */

// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *sortedMerge(ListNode *head1, ListNode *head2)
    {

        // base case if any of the halves is null
        if (head1 == NULL)
            return head2;

        if (head2 == NULL)
            return head1;

        // recursive part
        ListNode *tail;

        if (head1->val > head2->val)
        {

            tail = head2;
            tail->next = sortedMerge(head1, head2->next);
        }
        else
        {

            tail = head1;
            tail->next = sortedMerge(head1->next, head2);
        }

        // this will be the new head of the list
        return tail;
    }

private:
    ListNode *findMiddleNode(ListNode *head)
    {

        // when only one node or head itself null
        if (head or head->next == NULL)
            return head;

        ListNode *slow, *fast;
        slow = head;
        fast = head->next;

        while (fast != NULL and fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {

        // base case for single node or empty node
        if (head == NULL or head->next == NULL)
            return head;

        // recursive case

        // devide list into two equal halves
        ListNode *mid = findMiddleNode(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        // sort the two halves
        left = sortList(left);
        right = sortList(right);

        // merge the two sorted part
        ListNode *sortedHead = sortedMerge(left, right);

        return sortedHead;
    }
};
