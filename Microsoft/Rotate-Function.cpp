/*
    396. Rotate Function
    TC: O(N)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        int n = nums.size();
        int sum = 0, f = 0;

        for (int i = 0; i < n; i++)
        {

            // Array Sum
            sum += nums[i];

            // F(0)
            f += i * nums[i];
        }

        int ans = f;

        for (int i = 1; i < n; i++)
        {

            // F(k) = F(k-1) + sum - n*nums[n-1]
            f = f + sum - (n * nums[n - i]);
            ans = max(ans, f);
        }

        return ans;
    }
};

/*
Hint:
F(0) = 0A + 1B + 2C +3D
F(1) = 0D + 1A + 2B +3C
F(2) = 0C + 1D + 2A +3B
F(3) = 0B + 1C + 2D +3A

sum = 1A + 1B + 1C + 1D

F(1)-F(0) = a+b+c-3d
= a+b+c+d - 4d
= sum - n * Bk[0];

F(1) = F(0) + sum - n*Bk[0]
(where Bk[0] is the first element when array is rotated k-times).

Similarly,
F(1) = F(0) + sum - 4D
F(2) = F(1) + sum - 4C
F(3) = F(2) + sum - 4B

So,
F(k) = F(k-1) + sum - nBk[0]

Bk -->
k = 0; B[0] = nums[0];
k = 1; B[0] = nums[len-1];
k = 2; B[0] = nums[len-2];
*/