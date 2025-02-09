/*Given an array of integers nums and an integer target, return the indices i and j
 such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j
that satisfy the condition.

Return the answer with the smaller index first.*/

#include <bits/stdc++.h>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

/* Iteration 1 (i = 0):

nums[0] = 2, so complement = 9 - 2 = 7
7 is NOT in mp
Store {2 → 0} in mp
HashMap after step 1:

ini
Copy
Edit
mp = { 2 → 0 }
Iteration 2 (i = 1):

nums[1] = 7, so complement = 9 - 7 = 2
2 is found in mp at index 0
So, return {0, 1}
Result: [0, 1] (smallest index first)*/