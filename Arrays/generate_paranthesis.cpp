/*Generate Parentheses
Solved
You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example 1:

Input: n = 1

Output: ["()"]
Example 2:

Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void backtrack(int openN, int closeN, int n, vector<string> &res, string &stack)
    {
        if (openN == closeN && openN == n)
        {
            res.push_back(stack);
            return;
        }
        if (openN < n)
        {
            stack += '(';
            backtrack(openN + 1, closeN, n, res, stack);
            stack.pop_back();
        }
        if (closeN < openN)
        {
            stack += ')';
            backtrack(openN, closeN + 1, n, res, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);

        return res;
    }
};
