/*
973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> maxheap;
        for (auto point : points)
        {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y;
            maxheap.push({dist, point});
            if (maxheap.size() > k)
            {
                maxheap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxheap.empty())
        {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
};