/*

Code
Testcase
Test Result
Test Result
16. 3Sum Closest
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX / 2;

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (abs(current_sum - target) < abs(closest_sum - target))
                {
                    closest_sum = current_sum;
                }
                if (current_sum < target)
                {
                    ++left;
                }
                else if (current_sum > target)
                {
                    --right;
                }
                else
                {
                    return current_sum;
                }
            }
        }

        return closest_sum;
    }
};