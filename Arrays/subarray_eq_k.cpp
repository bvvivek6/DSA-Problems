/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;

        mp[sum]++;

        for (auto i : nums)
        {
            sum += i;
            int find = sum - k;
            if (mp.find(find) != mp.end())
            {
                count += mp[find];
            }
            mp[sum]++;
        }
        return count;
    }
};

/*
Index	it (Current Num)	sum (Prefix Sum)	find = sum - k	mp[find] (if exists)	ans (Subarrays Found)	mp After Update
0	1	1	1 - 3 = -2	❌ Not found	0	{0:1, 1:1}
1	2	3	3 - 3 = 0	✅ Found (mp[0] = 1)	1	{0:1, 1:1, 3:1}
2	3	6	6 - 3 = 3	✅ Found (mp[3] = 1)	2	{0:1, 1:1, 3:1, 6:1}
*/