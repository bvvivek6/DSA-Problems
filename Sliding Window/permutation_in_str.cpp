/*Permutation in String

You are given two strings s1 and s2.
Return true if s2 contains a permutation of s1, or false otherwise.
That means if a permutation of s1 exists as a substring of s2, then return true.
Both strings only contain lowercase letters.

Example 1:
Input: s1 = "abc", s2 = "lecabee"
Output: true*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        vector<int> count1(26, 0), count2(26, 0);
        for (char c : s1)
        {
            count1[c - 'a']++;
        }
        int left = 0, right = 0;
        while (right < s2.size())
        {
            count2[s2[right] - 'a']++;
            if ((right - left + 1) > s1.size())
            {
                count2[s2[left] - 'a']--;
                left++;
            }
            if (count1 == count2)
            {
                return true;
            }
            right++;
        }
        return false;
    }
};
