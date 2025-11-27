#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // if word1 is empty then we have insert m elements to the word1
        //  if word2 is empty then we have to delete n elements from the word1
        //  so to return the values of those base cases we assign the first row and col of the memo table with the size of the words

        for (int i = 0; i <= n; ++i)
            dp[i][0] = i; // insertion
        for (int i = 0; i <= m; ++i)
            dp[0][i] = i; // deletion

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // if the word is same
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // is there are not equal then we have 3 operations to perform
                //  insert (i-1,j) delete (i,j-1) replace (i-1,j-1);
                else
                {
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // delete
                                       dp[i][j - 1],    // insert
                                       dp[i - 1][j - 1] // replace
                                   });
                }
            }
        }

        return dp[n][m];
    }
};