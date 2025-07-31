/*Valid Palindrome
Solved
Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start < end)
        {
            // Ignore non alphanumeric
            while (start < end && !isalnum(s[start]))
                start++;
            while (start < end && !isalnum(s[end]))
                end--;

            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
