/*
Balanced Binary Tree
Solved 
Given a binary tree, return true if it is height-balanced and false otherwise.

A height-balanced binary tree is defined as a binary tree in which the left and right
subtrees of every node differ in height by no more than 1.*/

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
class solution{
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode * root){
        if(!root){
            return 0;
        }

        return 1+max(height(root->left), height(root->right));
    }
};