/*Two Integer Sum II
Solved 
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use 
O
(
1
)
O(1) additional space.*/

#include <bits/stdc++.h>
using namespace std;
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end= numbers.size()-1;
        while(start<end){
            if(numbers[start]+numbers[end]==target){
                return {start+1,end+1};
            }
            if(numbers[start]+numbers[end]<target){
                start++;
            }else{
                end--;
            }
        }
    }
};
    