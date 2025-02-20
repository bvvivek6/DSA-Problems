/*
Lowest Common Ancestor in Binary Search Tree
Solved 
Given a binary search tree (BST) where all node values are unique,
 and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.

The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants.
 The ancestor is allowed to be a descendant of itself.*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
             TreeNode * cur=root;
    
             while(cur){
                if(p->val> cur->val && q->val> cur->val){
                    cur=cur->right;
                }else if(p->val< cur->val && q->val <cur->val){
                    cur=cur->left;
                }else{
                    return cur;
                }
             }
             return NULL;
        }
    };