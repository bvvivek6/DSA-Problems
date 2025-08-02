/*

61. Rotate List
Given the head of a linked list, rotate the list to the right by k places
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

*/

#include <bits/stdc++.h>
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = 1;
        if (!head)
        {
            return head;
        }
        ListNode *temp = head;
        if (k == 0)
        {
            return head;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }
        int pos = k % len;
        if (pos == 0)
            return head;
        ListNode *curr = head;
        for (int i = 0; i < len - pos - 1; i++)
        {
            curr = curr->next;
        }
        ListNode *newHead = curr->next;
        curr->next = NULL;
        temp->next = head;

        return newHead;
    }
};