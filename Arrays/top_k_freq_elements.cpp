/*Top K Frequent Elements
Solved 
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int>count;
            for (int x : nums) {
                count[x]++;
            }
    
            vector<pair<int, int>> arr;
            for (auto p : count) {
                arr.push_back({p.second, p.first});
            }
            sort(arr.rbegin(), arr.rend());
    
            vector<int>ans;
            for (int i = 0; i < k; ++i) {
                ans.push_back(arr[i].second);
            }
            return ans;
        }
    };
    