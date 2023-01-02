/*
    299. Bulls and Cows
    TC: O(N)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {

        int n = secret.size();
        
        // Range is 0 to 9
        vector<int> s(10, 0);
        vector<int> g(10, 0);

        // Count
        int bull = 0, cow = 0;

        for (int i = 0; i < n; i++)
        {

            // Digits in the guess that are in the correct position
            if (secret[i] == guess[i])
                bull++;

            // Count the number of unpaired digits
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++)
        {

            // The less one is the cow number
            cow += min(s[i], g[i]);
        }

        return to_string(bull) + 'A' + to_string(cow) + 'B';
        ;
    }
};