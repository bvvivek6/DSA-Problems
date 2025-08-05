/*

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *temp = head->next;
        head->next = head->next->next;
        temp->next = head;

        head->next = swapPairs(head->next);

        return temp;
    }
};
