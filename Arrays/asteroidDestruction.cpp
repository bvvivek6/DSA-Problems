/*
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right,
negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();

        for (auto rock : asteroids)
        {
            bool destroyed = false;
            while (!st.empty() && rock < 0 && st.top() > 0) // for knowning the direction of the asteroid
            {
                if (abs(st.top() < abs(rock)))
                {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(rock))
                {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed)
            {
                st.push(rock);
            }
        }
        vector<int> ans(st.size());

        for (int j = st.size() - 1; j >= 0; j--)
        {
            ans[j] = st.top();
            st.pop();
        }
        return ans;
    }
};