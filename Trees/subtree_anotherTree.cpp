/*

Subtree of Another Tree
Solved 
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same 
structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself.*/

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
    
        bool sametree(TreeNode* root, TreeNode* subRoot){
            if(root==NULL && subRoot==NULL){
                return true;
            }
            if( root && subRoot && root->val==subRoot->val){
               return sametree(root->left, subRoot->left) && sametree(root->right, subRoot->right);
            }
            return false;
        }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if(!subRoot){
                return true;
            }
            if(!root){
                return false;
            }
            if(sametree(root,subRoot)){
                return true;
            }
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
    };
    