/*
3195. Find the Minimum Area to Cover All Ones I
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area,
uch that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

Example 1:
Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation:

The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
Example 2:
Input: grid = [[1,0],[0,0]]
Output: 1
Explanation:

The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int top = row;
        int left = col;
        int bottom = -1;
        int right = -1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if (grid[i][j])
                {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        return (bottom - top + 1) * (right - left + 1);
    }
};