#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> q;

        for (int i = 0; i < nums.size(); i++)
        {
            // remove the left elements as window forwards
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop_front();
            }

            // pop smaller elements from q
            while (!q.empty() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            // push the max element to the ans vector
            if (i - k + 1 >= 0)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};