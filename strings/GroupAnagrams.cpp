/*


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); // Sort the string to create a key
            mp[key].push_back(s);         // Group anagrams by the sorted key
        }

        vector<vector<string>> result;
        for (auto x : mp)
        {
            result.push_back(x.second);
        }
        return result;
    }
};