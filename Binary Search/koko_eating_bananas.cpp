/*Koko Eating Bananas
Solved 
You are given an integer array piles where piles[i] is the number of bananas in the ith pile. You are also given an integer h, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer k such that you can eat all the bananas within h hours.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int left = 1;
            int right = *max_element(piles.begin(), piles.end()); //max speed of the monkey to eat
            int result = right;
    
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long total_time = 0;
    
                for (int pile : piles) {
                    total_time += (pile + mid - 1) / mid; //Ceiling Division Trick ///remember this!!
                }
    
                if (total_time <= h) {
                    result = mid; //Try to minimize the speed
                    right = mid - 1;
                } else {
                    left = mid + 1; // Increase speed if time > h
                }
            }
    
            return result;
        }
    };
    