/*


*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }

        queue<TreeNode *> que;
        que.push(root);
        bool leftToRight = true;

        while (!que.empty())
        {
            int size = que.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();

                level.push_back(node->val);

                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            // If the current level is right to left, reverse the level
            if (!leftToRight)
            {
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            leftToRight = !leftToRight; // Toggle the direction
        }
        return result;
    }
};
