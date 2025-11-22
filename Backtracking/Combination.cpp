#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int> &sub, int n, int k)
    {

        if (sub.size() == k)
        {
            ans.push_back(sub);
        }
        for (int i = index; i <= n; ++i)
        {
            sub.push_back(i);
            backtrack(i + 1, sub, n, k);
            sub.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> sub;
        backtrack(1, sub, n, k);
        return ans;
    }
};