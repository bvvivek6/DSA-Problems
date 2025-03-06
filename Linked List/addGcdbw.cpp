/*

2807. Insert Greatest Common Divisors in Linked List
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.*/

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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *cur = head->next;
        while (cur != NULL)
        {
            int gcd = __gcd(prev->val, cur->val);
            ListNode *newNode = new ListNode(gcd);
            prev->next = newNode;
            newNode->next = cur;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};