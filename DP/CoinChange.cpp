/*
322. Coin Change
Medium
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int coinChange(vector<int> &coins, int amount)
    {

        if (amount < 1)
        {
            return 0;
        }

        // declare dp array
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // base case

        for (int i = 1; i <= amount; i++)
        {

            for (auto c : coins)
            {
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        // retrun the ans
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};