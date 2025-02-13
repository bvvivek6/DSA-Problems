/*Search a 2D Matrix
Solved 
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows= matrix.size(), cols= matrix[0].size();
            //treat 2d matrix as 1D array
            int l=0;
            int r= rows*cols -1; //point to end of the 1D array
    
            while(l<=r){
                int mid= l+(r-l)/2;
                int row= mid/cols, col=mid%cols; //to convert 1D pointer to 2D pointer
    
                if(matrix[row][col]==target){
                    return true;
                }else if( target<matrix[row][col]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return false;
        }
    };
     