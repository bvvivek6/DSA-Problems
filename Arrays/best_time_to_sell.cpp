/*Best Time to Buy and Sell Stock
Solved
You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1;
        int maxpr = 0;

        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                maxpr = max(maxpr, profit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return maxpr;
    }
};
