/*Given an integer array nums, return true if any value appears more than once in the array, 
otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false*/

#include <bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>mark;
        for(int n: nums){
            if(mark.count(n)){
                return true;
            }
            mark.insert(n);
        }
        return false;
    }
};
