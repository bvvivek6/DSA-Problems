/*Longest Consecutive Sequence
Solved 
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> snum(nums.begin(), nums.end());
    
            int longest = 0;
    
            for( int num :  snum){
                if(snum.find(num-1)==snum.end()){
                    int length=1;
                    while(snum.find(num+length)!= snum.end()){
                        length++;
                    }
                    longest=max(longest, length);
                }
            }
            return longest;
        }
    };
    