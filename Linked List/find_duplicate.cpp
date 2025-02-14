/*Find the Duplicate Number
Solved 
You are given an array of integers nums containing n + 1 integers. 
Each integer in nums is in the range [1, n] inclusive.

Every integer appears exactly once, except for one integer which appears two or more times. 
Return the integer that appears more than once.*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int findDuplicate(vector<int>& nums) {

            //Floyd's tortoise algo fast and slow pointers
            //nice approach
            /*
            This of the array as linked list
            eg: [1,2,3,2,2]
                1->2->3->2->2

                slow = nums[slow] -> nums[1] -> 3
                fast = nums[nums[fast]] -> nums[nums[1]] -> nums[3] -> 2

            */

            int slow=nums[0];
            int fast= nums[0];
    
            do{
                slow=nums[slow];
                fast=nums[nums[fast]]; //2 steps
            }while(slow!=fast);
    
            slow=nums[0];
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
                /*
                    slow = nums[slow] -> nums[1] -> 3
                    fast = nums[fast] -> nums[2] -> 4

                    slow = nums[slow] -> nums[3] -> 2
                    fast = nums[fast] -> nums[4] -> 2
                */
            }
            return slow;
        }
    };
    