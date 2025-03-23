/*881. Boats to Save People

You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries
at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int left = 0;
        int right = people.size() - 1;
        sort(people.begin(), people.end());

        int boat = 0;
        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
            {
                left++;
            }
            right--;
            boat++;
        }
        return boat;
    }
};