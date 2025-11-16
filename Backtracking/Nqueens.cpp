#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafePlace(int n, vector<string> &nQueens, int row, int col)
    {
        // Check if there's any queen in the same column above current position
        for (int i = 0; i < n; i++)
        {
            if (nQueens[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check upper-left diagonal for any queen
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check upper-right diagonal for any queen
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void solveNQueens(int n, vector<vector<string>> &output, vector<string> &nQueens, int row)
    {

        if (row == n)
        {
            output.push_back(nQueens);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafePlace(n, nQueens, row, col))
            {
                // Place queen
                nQueens[row][col] = 'Q';
                //  next row
                solveNQueens(n, output, nQueens, row + 1);
                // Backtrack: remove queen for trying next position
                nQueens[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> output;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
};