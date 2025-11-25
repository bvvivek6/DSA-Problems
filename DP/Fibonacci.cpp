#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &dp, int n)
    {

        if (n <= 1)
        {
            return n;
        }
        if (dp[n] != -1) // to check if the value is already computed, return it 
        {
            return dp[n];
        }
        dp[n] = helper(dp, n - 1) + helper(dp, n - 2);
        return dp[n];
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = helper(dp, n);
        return ans;
    }
};