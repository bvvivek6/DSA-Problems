#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {

                                                       };
};

class Solution
{
public:
    int maxSum = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        int currentSum = root->val + left + right; // peak node, passing through that

        maxSum = max(maxSum, currentSum);

        // return the max len
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxSum;
    }
};