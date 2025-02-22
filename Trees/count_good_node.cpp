/*
Count Good Nodes in Binary Tree
Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains no nodes with a value greater than the value of node x

Given the root of a binary tree root, return the number of good nodes within the tree.*/

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
    int goodnodes(TreeNode *root){
        return dfs(root, root->val);
    }

    int dfs(TreeNode *node, int maxVal){
        if(!node){
            return 0;
        }
        int count=(node->val>=maxVal)?1:0;
        maxVal=max(node->val, maxVal);
        count+=dfs(node->left, maxVal);
        count+=dfs(node->right, maxVal);
        return count;
    }
};