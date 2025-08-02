/*
289. Game of Life
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular
automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state:
live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors
 (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

-Any live cell with fewer than two live neighbors dies as if caused by under-population.
-Any live cell with two or three live neighbors lives on to the next generation.
-Any live cell with more than three live neighbors dies, as if by over-population.
-Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell
 in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
Given the current state of the board, update the board to reflect its next state.
Note that you do not need to return anything.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<vector<int>> &board, int row, int col, int i, int j)
    {
        int live = 0;

        // upper
        if (i > 0)
        {
            if (board[i - 1][j])
            {
                live++;
            }
        }
        // lower
        if (i < row - 1)
        {
            if (board[i + 1][j])
            {
                live++;
            }
        }
        // left
        if (j > 0)
        {
            if (board[i][j - 1])
            {
                live++;
            }
        }
        // right
        if (j < col - 1)
        {
            if (board[i][j + 1])
            {
                live++;
            }
        }

        // down diagonal
        if (i < row - 1 && j < col - 1)
        {
            if (board[i + 1][j + 1])
            {
                live++;
            }
        }

        // up diagonal
        if (i > 0 && j > 0)
        {
            if (board[i - 1][j - 1])
            {
                live++;
            }
        }

        // up right
        if (i > 0 && j < col - 1)
        {
            if (board[i - 1][j + 1])
            {
                live++;
            }
        }
        // down left
        if (i < row - 1 && j > 0)
        {
            if (board[i + 1][j - 1])
            {
                live++;
            }
        }

        return live;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> temp = board;
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                int livenei = helper(temp, row, col, i, j);

                if (!board[i][j])
                {
                    if (livenei == 3)
                    {
                        board[i][j] = 1;
                    }
                }
                else if (board[i][j])
                {
                    if (livenei < 2 || livenei > 3)
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};