/*Valid Parentheses
Solved 
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true
Example 3:

Input: s = "[(])"

Output: false*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> closetoopen={{')','('},{']','['},{'}','{'}}; 

        for( char c : s){
            if(closetoopen.count(c)){ //if its closing bracket
                if(!stack.empty() && stack.top()==closetoopen[c]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(c); //opening bracket
            }
        }
        return stack.empty();
    }
};
    