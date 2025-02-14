/*Add Two Numbers
You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

The digits are stored in reverse order, e.g. the number 123 is represented as 3 -> 2 -> 1 -> in the linked list.

Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Return the sum of the two numbers as a linked list.*/

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode();
            ListNode* cur = dummy;
    
            int carry=0;
            while(l1!=NULL || l2!=NULL || carry!=0){
                int n1=(l1!=NULL)?l1->val:0;
                int n2=(l2!=NULL)?l2->val:0;
                
                int sum= n1+n2+carry;
                carry=sum/10;
                sum=sum%10;
                cur->next=new ListNode(sum);
    
                cur=cur->next;
                l1 = (l1 != NULL) ? l1->next : NULL;
                l2 = (l2 != NULL) ? l2->next : NULL;
            }
            ListNode *ans= dummy->next;
            delete dummy;
            return ans;
    
        }
    };