/*Given an array of strings strs, group all anagrams together into sublists. 
You may return the output in any order.

An anagram is a string that contains the exact same characters as 
another string, but the order of the characters can be different.*/

#include <bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string , vector<string>> am;
    
            for(auto word : strs){
                string sword= word;
                sort(sword.begin(),sword.end());
                am[sword].push_back(word); // act: cat,act
            }
    
            vector<vector<string>> ans;
            for ( auto x: am){
                ans.push_back(x.second);
            }
            return ans;
        }
    };
    