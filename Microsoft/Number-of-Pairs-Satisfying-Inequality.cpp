/*
    2426. Number of Pairs Satisfying Inequality
    TC: O(N)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
private:
    ll pairCount(vector<ll> &nums, ll start, ll end, ll diff)
    {

        // If partition contains single element, it can't produce any pair
        if (start == end)
            return 0;

        ll mid = start + (end - start) / 2;

        // Get possible pair count from left and right partition
        ll count = pairCount(nums, start, mid, diff) + pairCount(nums, mid + 1, end, diff);

        // Size of first array
        ll length1 = mid - start + 1;

        // Size of second array
        ll length2 = end - mid;

        // Array to copy data from source array to perform sort
        vector<ll> iArray(length1);
        vector<ll> jArray(length2);

        // Main array's index
        ll mainArrayIndex = start;

        // Copy first part in iArray
        for (ll i = 0; i < length1; i++)
            iArray[i] = nums[mainArrayIndex++];

        // Copy second part in jArray
        for (ll j = 0; j < length2; j++)
            jArray[j] = nums[mainArrayIndex++];

        for (ll j = 0; j < length2; j++)
        {

            // nums[i] <= nums[j] + diff
            ll D = jArray[j] + diff;

            // Returns an iterator pointing to the first element in the range [first, last)
            // that is greater than value, or last if no such element is found.
            count += upper_bound(iArray.begin(), iArray.end(), D) - iArray.begin();
        }

        // Iterators
        ll idx1 = 0, idx2 = 0;
        mainArrayIndex = start;

        // Merge 2 sorted arrays
        // Whichever value is lesser put that first into main array
        while (idx1 < length1 && idx2 < length2)
        {

            if (iArray[idx1] < jArray[idx2])
                nums[mainArrayIndex++] = iArray[idx1++];
            else
                nums[mainArrayIndex++] = jArray[idx2++];
        }

        // Any excess values left in iArray put that in main array
        while (idx1 < length1)
        {

            nums[mainArrayIndex] = iArray[idx1];
            idx1++;
            mainArrayIndex++;
        }

        // Any excess values left in jArray put that in main array
        while (idx2 < length2)
        {

            nums[mainArrayIndex] = jArray[idx2];
            idx2++;
            mainArrayIndex++;
        }

        return count;
    }

public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {

        int n = nums1.size();
        vector<ll> nums(n);

        // According to modified equation
        for (int i = 0; i < n; i++)
            nums[i] = nums1[i] - nums2[i];

        // Return total count
        return pairCount(nums, 0, n - 1, diff);
    }
};

/*
    Approach:
        nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
    =>  nums1[i] - nums2[i] - nums1[j] + nums2[j] <= diff
    =>  (nums1[i] - nums2[i]) - (nums1[j] - nums2[j]) <= diff
    =>  nums[i] - nums[j] <= diff   [Array with values i.e nums[i] = nums1[i] - nums2[i]]
    =>  nums[i] <= nums[j] + diff   [i contains in first part, j in second]
*/