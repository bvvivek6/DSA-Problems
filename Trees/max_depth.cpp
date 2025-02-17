/*
Maximum Depth of Binary Tree
Solved 
Given the root of a binary tree, return its depth.

The depth of a binary tree is defined as the number of nodes along the
longest path from the root node down to the farthest leaf node.*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root==NULL){
                return 0;
            }
            
            return 1+max(maxDepth(root->left), maxDepth(root->right)); 
        }
    };