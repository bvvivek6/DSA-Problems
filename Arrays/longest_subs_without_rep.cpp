/*Longest Substring Without Repeating Characters
Solved 
Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> charSet;
            int l = 0;
            int res = 0;
    
            for (int r = 0; r < s.size(); r++) {
                while (charSet.find(s[r]) != charSet.end()) {
                    charSet.erase(s[l]);
                    l++;
                }
                charSet.insert(s[r]);
                res = max(res, r - l + 1);
            }
            return res;
        }
    };