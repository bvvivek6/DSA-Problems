#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int> &sub, vector<int> &nums)
    {
        ans.push_back(sub);

        for (int i = index; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            backtrack(i + 1, sub, nums);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> sub;
        backtrack(0, sub, nums);
        return ans;
    }
};