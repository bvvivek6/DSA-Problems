/*130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells
are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return
anything.



Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]



So the trick is:
Find all safe 'O' cells first (those touching the border).
Mark them temporarily (e.g., 'V').
Flip everything else to 'X' (because those are truly surrounded).
Restore safe cells back to 'O'.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int r, int c, int rows, int cols)
    {
        return (r >= 0 && c >= 0 && r < rows && c < cols);
    }

    void floodfill(int r, int c, int rows, int cols, vector<vector<char>> &board)
    {
        board[r][c] = 'V';

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto &d : dir)
        {
            int newr = r + d[0];
            int newc = c + d[1];
            if (isSafe(newr, newc, rows, cols) && board[newr][newc] == 'O')
            {
                floodfill(newr, newc, rows, cols, board);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        int rows = board.size();
        int cols = board[0].size();

        // Step 1: Mark all border-connected 'O's as 'V'
        // Top and bottom rows
        for (int j = 0; j < cols; j++)
        {
            if (board[0][j] == 'O')
                floodfill(0, j, rows, cols, board);
            if (board[rows - 1][j] == 'O')
                floodfill(rows - 1, j, rows, cols, board);
        }
        // Left and right columns
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
                floodfill(i, 0, rows, cols, board);
            if (board[i][cols - 1] == 'O')
                floodfill(i, cols - 1, rows, cols, board);
        }

        // Step 2: Flip all remaining 'O's to 'X'
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // Step 3: Convert 'V' back to 'O'
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'V')
                    board[i][j] = 'O';
            }
        }
    }
};
