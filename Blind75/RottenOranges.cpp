/*
994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;
        int fresh = 0;
        int minutes = 0;

        // 1) count all the rotten and fresh, rotten to queue, fresh-> counter
        // 2) bfs from the queue and mark all the surronding ones rotten and push the rotten back to queue and iterate to all the oranges

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!que.empty() && fresh > 0)
        {

            int size = que.size();
            minutes++;

            for (int i = 0; i < size; i++)
            {
                auto [x, y] = que.front();
                que.pop(); // take the rotten tomato

                // rot all the 4 directions
                for (auto [dx, dy] : dir)
                {

                    // new coordinates
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1)
                    {
                        fresh--;
                        grid[nx][ny] = 2; // rot
                        que.push({nx, ny});
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
