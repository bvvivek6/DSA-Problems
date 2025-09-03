#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0;
        int left = 0;
        unordered_map<char, int> mp{{'a', 0}, {'b', 0}, {'c', 0}};

        for (int right = 0; right < s.size(); right++)
        {
            mp[s[right]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
            {
                count += s.size() - right;
                mp[s[left]]--;
                left++;
            }
        }
        return count;
    }
};