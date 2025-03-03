/*190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case,
both input and output will be given as a signed integer type. They should not affect your implementation,
as the integer's internal binary representation is the same, whether it is signed or unsigned.


Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans = (ans << 1) | (n & 1);
            n = n >> 1;
        }
        return ans;
    }
};