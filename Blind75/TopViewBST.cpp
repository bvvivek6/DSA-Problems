#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }

        // bfs approach
        map<int, int> noded;

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            // if the node is not present
            if (noded.find(hd) == noded.end())
            {
                noded[hd] = node->data;
            }
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // store the values in the result array as order;

        for (auto x : noded)
        {
            result.push_back(x.second);
        }

        return result;
    }
};