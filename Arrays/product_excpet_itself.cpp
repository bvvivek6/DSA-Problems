/*Products of Array Except Self
Solved 
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in 
O
(
n
)
O(n) time without using the division operation?*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
           int n=nums.size();
           vector<int>ans(n,1);
    
           for(int i=1;i<n;i++){
                ans[i]=ans[i-1]*nums[i-1];
            }
    
            int pf=1;
            for(int i=n-1;i>=0;i--){
                ans[i]*=pf;
                pf*=nums[i];
            }
            return ans;
    
        }
    };
    