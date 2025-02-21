/*
Binary Tree Level Order Traversal
Solved 
Given a binary tree root, return the level order traversal of it as a nested list, where each sublist contains
the values of nodes at a particular level in the tree, from left to right.
Input: root = [1,2,3,4,5,6,7]

Output: [[1],[2,3],[4,5,6,7]]


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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(!root){
                return ans;
            }
            queue<TreeNode *> que;
            que.push(root);
    
            while(!que.empty()){
                vector<int>level;
                int size=que.size();
    
                for(int i=0;i<size;i++){
                    TreeNode * node=que.front();
                    que.pop();
    
                    if(node){
                        level.push_back(node->val);
                        que.push(node->left);
                        que.push(node->right);
                    }
                }
                if(!level.empty()){
                    ans.push_back(level);
                }    
           }
    
           return ans;
        }
    };
    