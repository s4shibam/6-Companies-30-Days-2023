/*
    581. Shortest Unsorted Continuous Subarray
    TC: O(N)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        int n = nums.size();
        int start = n - 1, end = 0;

        // Initially first element is the max, last element is the min
        int maxi = 0, mini = n - 1;

        for (int i = 0; i < n; i++)
        {

            // For backward traversal
            int j = (n - i - 1);

            // It is fine when we are getting maximum or equal in every step rightwards
            if (nums[maxi] <= nums[i])
                maxi = i;
            else
                end = i;

            // It is fine when we are getting minimum or equal in every step leftwards
            if (nums[j] <= nums[mini])
                mini = j;
            else
                start = j;
        }

        // 'end' must be greater than 'start'
        // If not, array must be already sorted or size is 1, return 0
        if (start >= end)
            return 0;

        return (end - start + 1);
    }
};