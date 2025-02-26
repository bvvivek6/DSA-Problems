/*Daily Temperatures
Solved 
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n= temperatures.size();
            stack<int> temp;
            vector<int>ans(n,0);
            int count=0;
            //int itemp=temperatures[0];
            for(int i=0;i<n;i++){
                while(!temp.empty() && temperatures[i]>temperatures[temp.top()]){
                    int index=temp.top();
                    temp.pop();
                    ans[index]=i-index; //difference of the days
                }
                temp.push(i);
                count++;
            }
            return ans;
        }
    };
    