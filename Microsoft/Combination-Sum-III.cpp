/*
    216. Combination Sum III
    TC: InternalNodes in the RecursionTree   +   K * LeafNodes in RecursionTree
                  = (C(9,0) + C(9,1) + ... + C(9,K-1))   +   K * C(9,K)
        In our solution, the worst case will happen when k = 8. Then Total Time Complexity = O(574) which is O(1)

    SC: O(k) -> Depth of Recursion tree + Size of TempList

    K = Input size of each combination.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int i, int k, int n, vector<int> &num, vector<int> &com, vector<vector<int>> &ans)
    {

        // Last index of num array
        if (i == num.size())
        {
            // k numbers are selected
            if (k == com.size())
                // Sum value is n
                if (n == 0)
                    // Push the valid combination
                    ans.push_back(com);

            return;
        }

        if (n >= num[i])
        {

            // Add value in the combination
            com.push_back(num[i]);

            // Pick the current index value
            helper(i + 1, k, n - num[i], num, com, ans);

            // Remove value from the combination
            com.pop_back();
        }

        // Not pick the current index value
        helper(i + 1, k, n, num, com, ans);
    }

public:
    // Main
    vector<vector<int>> combinationSum3(int k, int n)
    {

        // Declare array to store values from 1 to 9
        vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // Each combination
        vector<int> com;
        // All combinations
        vector<vector<int>> ans;

        helper(0, k, n, num, com, ans);
        return ans;
    }
};