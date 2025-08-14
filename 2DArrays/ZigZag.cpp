/*
498. Diagonal Traverse
Given an m x n matrix mat, 
return an array of all the 
elements of the array in a diagonal order.


Example 1: Input: mat = [[1,2,3],[4,5,6],[7,8,9]] Output: [1,2,4,7,5,3,6,8,9] Example 2:

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return {};

        int rows = mat.size();
        int cols = mat[0].size();
        int r = 0, c = 0;
        int direction = 1; // 1 → up-right, -1 → down-left
        vector<int> result;
        result.reserve(rows * cols);

        for (int i = 0; i < rows * cols; i++)
        {
            result.push_back(mat[r][c]);

            if (direction == 1)
            { // moving up-right
                if (c == cols - 1)
                { // last column → go down
                    r++;
                    direction = -1;
                }
                else if (r == 0)
                { // first row → go right
                    c++;
                    direction = -1;
                }
                else
                { // move up-right
                    r--;
                    c++;
                }
            }
            else
            { // moving down-left
                if (r == rows - 1)
                { // last row → go right
                    c++;
                    direction = 1;
                }
                else if (c == 0)
                { // first column → go down
                    r++;
                    direction = 1;
                }
                else
                { // move down-left
                    r++;
                    c--;
                }
            }
        }
        return result;
    }
};