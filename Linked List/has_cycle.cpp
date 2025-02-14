/*Linked List Cycle Detection
Given the beginning of a linked list head, return true if there is a cycle in the linked list. Otherwise, return false.

There is a cycle in a linked list if at least one node in the list that can be visited again by following the next pointer.

Internally, index determines the index of the beginning of the cycle, if it exists. The tail node of the list will set it's next pointer to the index-th node.
 If index = -1, then the tail node points to null and no cycle exists.*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool hasCycle(ListNode* head) {
            ListNode *fast=head;
            ListNode *slow=head;
            
            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow){
                    return true;
                }
            }
            return false;
        }
    };
    
