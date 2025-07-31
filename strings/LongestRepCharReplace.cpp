/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
 You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int maxfreq = 0;
        int maxlen = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            if ((right - left + 1) - maxfreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};

/* -------- or ---------- */
// get the max frequency of the character in the string and then check if the length of the
// substring minus the max frequency is less than or equal to k

class Solution2
{

public:
    int characterReplacement(string s, int k)
    {
        vector<int> globalFreq(26, 0);
        for (char c : s)
            globalFreq[c - 'A']++;

        char target = max_element(globalFreq.begin(), globalFreq.end()) - globalFreq.begin() + 'A';

        int left = 0, changes = 0, ans = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (s[right] != target)
                changes++;

            while (changes > k)
            {
                if (s[left] != target)
                    changes--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};