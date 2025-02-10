/*Container With Most Water
You are given an integer array heights where heights[i] represents the height of the
i
t
h
i
th
  bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int start = 0;
        int end = heights.size() - 1;
        int ans = 0;
        while (start < end)
        {
            int area = min(heights[start], heights[end]) * (end - start);
            ans = max(ans, area);
            if (heights[start] <= heights[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};
