/*394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.


Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> count;
        stack<string> stc;
        string ans = "";
        int rcount = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                rcount = rcount * 10 + (c - '0');
            }
            else if (c == '[')
            {
                count.push(rcount);
                stc.push(ans);
                rcount = 0;
                ans = "";
            }
            else if (c == ']')
            {
                int temp = count.top();
                count.pop();
                string temps = stc.top();
                stc.pop();
                string duplicates = "";

                for (int i = 0; i < temp; i++)
                {
                    duplicates += ans;
                }
                ans = temps + duplicates;
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};