#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void backtrack(int index, int target, vector<int> &sum, vector<int> &candidates)
    {
        if (target == 0)
        {
            ans.push_back(sum);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
            {
                break;
            }
            sum.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], sum, candidates);
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // sort to detect duplicatesw
        vector<int> sum;
        backtrack(0, target, sum, candidates);
        return ans;
    }
};
