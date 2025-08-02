/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minArrows(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int arrows = 1;
        int i = 1;
        int end = points[0][1];
        while (i < points.size())
        {
            if (points[i][0] >= end)
            {
                arrows++; // no overlap, need a new arrow
                end = points[i][1];
            }
            else
            {
                // overlap, update the end to the minimum of the current end and the new interval's end
                end = min(end, points[i][1]);
            }
            i++;
        }
        return arrows;
    }
};