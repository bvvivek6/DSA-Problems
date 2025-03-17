/*92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]*/

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head->next == NULL || left == right)
        {
            return head;
        }
        stack<int> st;
        ListNode *a = head;
        int index = 0;
        while (a != NULL)
        {
            index++;
            if (index >= left && index <= right)
            {
                st.push(a->val);
            }
            a = a->next;

            if (index > right)
            {
                break;
            }
        }
        a = head;
        index = 0;
        while (a != NULL)
        {
            index++;
            if (index >= left && index <= right)
            {
                a->val = st.top();
                st.pop();
            }

            a = a->next;
            if (index > right)
            {
                break;
            }
        }
        return head;
    }
};