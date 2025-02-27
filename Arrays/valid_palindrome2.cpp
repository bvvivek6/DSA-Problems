/*680. Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};