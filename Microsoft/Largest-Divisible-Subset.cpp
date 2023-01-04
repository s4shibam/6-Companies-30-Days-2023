/*
    368. Largest Divisible Subset
    TC: O(N)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> helper(int start, vector<int> &nums, unordered_map<int, vector<int>> &dp, int n)
    {

        // Handling overlapping sub-problems
        if (dp.count(start))
            return dp[start];

        // Try next elements
        for (int nxt = start + 1; nxt < n; nxt++)
        {

            // Only those completely divided by nums[start] are valid choice
            if (nums[nxt] % nums[start] == 0)
            {

                // com = largest subset on choosing nums[next]
                vector<int> com = helper(nxt, nums, dp, n);

                // dp[start] = largest subset till now when nums[start] is previous element
                if (com.size() > dp[start].size())
                    dp[start] = com;
            }
        }

        // Include nums[start] in dp
        dp[start].push_back(nums[start]);
        return dp[start];
    }

public:
    // Main
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> dp;

        // Stores the largest subset
        vector<int> ans;

        // Any element is valid choice for 1st subset member
        for (int i = 0; i < n; i++)
        {

            // Try for each & obtain largest subset when nums[i] is starting element
            vector<int> com = helper(i, nums, dp, n);

            // Keep track of largest subset found
            if (com.size() > ans.size())
                ans = com;
        }

        return ans;
    }
};