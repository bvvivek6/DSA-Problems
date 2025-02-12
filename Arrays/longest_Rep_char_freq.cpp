/*Longest Repeating Character Replacement
You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

After performing at most k replacements, return the length of the longest substring which contains only one distinct character.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            unordered_map<char,int> count;
            int ans=0;
            int l=0, maxfr=0;
    
            for(int r=0;r<s.size();r++){
                count[s[r]]++;
                maxfr=max(maxfr,count[s[r]]);
                while((r-l+1)-maxfr>k){ //the number of characters that need to be replaced to make the entire window consist of a single character..
                    count[s[l]]--;
                    l++;
                }
                ans=max(ans, r-l+1);
            }
            return ans;
        }
    };

    //If the window becomes invalid (needed replacements > k), we move l forward until it becomes valid again.
    