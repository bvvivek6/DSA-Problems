/*
Diameter of Binary Tree
Solved 
The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.

The length of a path between two nodes in a binary tree is the number of edges between the nodes.

Given the root of a binary tree root, return the diameter of the tree.
*/
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
    
        int dfs(TreeNode * root, int& res){
            if(root==NULL){
                return 0;
            }
    
            int left= dfs(root->left,res);
            int right= dfs(root->right,res);
            res=max(res, left+right);
    
            return 1+max(left,right);
        }
    
        int diameterOfBinaryTree(TreeNode* root) {
            int res=0;
            dfs(root,res);
            return res;
        }
    };