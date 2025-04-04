/*71. Simplify Path

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'.
 Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid
directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.


Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string ans, temp;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
                continue;

            temp = "";
            while (i < path.size() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }

            if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (temp != "." && !temp.empty())
            {
                st.push(temp);
            }
        }
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};