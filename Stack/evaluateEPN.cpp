/*Evaluate Reverse Polish Notation
Solved 
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.
Example 1:

Input: tokens = ["1","2","+","3","*","4","-"]

Output: 5*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> sum;
            for( auto num :  tokens){
                if ( num == "+"){
                    int a= sum.top(); sum.pop();
                    int b= sum.top(); sum.pop();
                    sum.push(a+b);
                }else if(num=="-"){
                     int a= sum.top(); sum.pop();
                    int b= sum.top(); sum.pop();
                    sum.push(b-a);
                }else if(num=="*"){
                     int a= sum.top(); sum.pop();
                    int b= sum.top(); sum.pop();
                    sum.push(a*b);
                }else if(num=="/"){
                     int a= sum.top(); sum.pop();
                    int b= sum.top(); sum.pop();
                    sum.push(b/a);
                }else{
                    sum.push(stoi(num));
                }
            }
            return sum.top();
        }
    };
    