/*
1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
 If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int s1 = word1.size(), s2 = word2.size();
        string ans;
        ans.reserve(s1 + s2); // Reserve memory to avoid reallocation

        int i = 0, j = 0;
        while (i < s1 || j < s2)
        {
            if (i < s1)
                ans += word1[i++];
            if (j < s2)
                ans += word2[j++];
        }
        return ans;
    }
};
