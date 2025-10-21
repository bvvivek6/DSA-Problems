/*
221. Maximal Square

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!i || !j || matrix[i][j] == '0')
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};

/*
 Find the largest square of 1s and return its area.
For each cell (i, j), check if it can be the bottom-right corner of a square.
Use results of top, left, and top-left cells to decide.


dp[i][j] = side length of largest square ending at (i, j).

If matrix[i][j] == "1":
    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
Else:
dp[i][j] = 0
First row and first column in dp are just copied from matrix (1 or 0).
Loop through the matrix.

Fill dp using the formula.

Keep track of max_side during the process.

Area = max_side * max_side.

Time: O(m * n)
Space: O(m * n) (or O(n) with optimization).*/