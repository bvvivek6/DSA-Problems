/*Reorder Linked List
Solved 
You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        void reorderList(ListNode* head) {
    
            //finding the middle of the list
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode *second=slow->next;
            ListNode *prev=slow->next=NULL;
    
            //reversing the Second list
            while (second != nullptr) {
                ListNode* tmp = second->next;
                second->next = prev;
                prev = second;
                second = tmp;
            }
            
            //joining the nodes acc to the qs
            ListNode* first = head;
            second = prev;
            while (second != nullptr) {
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
                first->next = second;
                second->next = temp1;
                first = temp1;
                second = temp2;
            }
            
        }
    };