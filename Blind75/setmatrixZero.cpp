/*
 73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> rowMarker(rows, 0);
        vector<int> colMarker(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowMarker[i] = 1;
                    colMarker[j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (rowMarker[i] == 1)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < cols; j++)
        {
            if (colMarker[j] == 1)
            {
                for (int i = 0; i < rows; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
