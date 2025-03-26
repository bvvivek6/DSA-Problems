/*918. Maximum Sum Circular Subarray

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element o
f nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for
a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int kadanes(vector<int> &arr)
    {
        int cur_sum = 0;
        int max_sum = INT_MIN;
        for (auto num : arr)
        {
            cur_sum = max(num, cur_sum + num);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
    int inversekadanes(vector<int> &arr)
    {
        int cur_sum = 0;
        int min_sum = INT_MAX;
        for (auto num : arr)
        {
            cur_sum = min(num, cur_sum + num);
            min_sum = min(min_sum, cur_sum);
        }
        return min_sum;
    }

public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total_sum = 0;
        int max_sum = kadanes(nums);
        int min_sum = inversekadanes(nums);
        total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum == min_sum)
        {
            return max_sum;
        }
        return max(max_sum, total_sum - min_sum);
    }
};