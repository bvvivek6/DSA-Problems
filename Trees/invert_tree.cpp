/*Invert Binary Tree
You are given the root of a binary tree root. Invert the binary tree and return its root.
Input: root = [1,2,3,4,5,6,7]

Output: [1,3,2,7,6,5,4]
*/
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
        TreeNode* invertTree(TreeNode* root) {
           if (root == NULL) {
                return NULL;
            }
    
            //swap
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
    
           
            invertTree(root->left);
            invertTree(root->right);
    
            return root;
    
        }
    };
    