/*
978. Longest Turbulent Subarray

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 1;

        int inc = 1, dec = 1, max_len = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                inc = dec + 1;
                dec = 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                dec = inc + 1;
                inc = 1;
            }
            else
            {
                inc = dec = 1;
            }
            max_len = max(max_len, max(inc, dec));
        }

        return max_len;
    }
};
