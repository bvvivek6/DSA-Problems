/*
Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal
length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;

        int minLength = INT_MAX;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while (sum >= target)
            {
                minLength = min(minLength, right - start + 1);
                sum -= nums[start++];
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};