#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int countSubstrings(string s)
    {
        int count = 0;
        // for odd length palindromes
        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }
        // for even palindromes
        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string s = "abc";
    cout << "Count of palindromic substrings in '" << s << "': " << solution.countSubstrings(s) << endl;

    s = "aaa";
    cout << "Count of palindromic substrings in '" << s << "': " << solution.countSubstrings(s) << endl;

    return 0;
}