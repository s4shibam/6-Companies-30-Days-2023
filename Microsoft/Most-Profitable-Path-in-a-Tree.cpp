/*
    2467. Most Profitable Path in a Tree
    TC: O(2(V + 2E))
    SC: O(4N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Find Bob's path to the 0th node along with time
    // Eg. Path: 5 -> 3 -> 2 -> 1
    // Time: 0 -> 1 -> 2 -> 3
    bool findBobPath(int node, int time, vector<int> &bVis, unordered_map<int, int> &bPath, vector<int> graph[])
    {

        // Current node is visited
        bVis[node] = 1;

        // Register the time
        bPath[node] = time;

        // If 0th node
        if (node == 0)
            return true;

        // Explore all neighbors
        for (auto nei : graph[node])
        {

            // If node not visited
            if (!bVis[nei])

                // Try to reach 0th node via current neighbour node
                if (findBobPath(nei, time + 1, bVis, bPath, graph))
                    return true;
        }

        // If unable to reach 0th node through current node
        // Erase this node from path and return false
        bPath.erase(node);
        return false;
    }

public:
    // Main
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {

        // Number of nodes
        int n = amount.size();
        vector<int> graph[n];

        // Adjacency List
        for (auto e : edges)
        {

            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> bVis(n, 0);        // Remembers visiting path for Bob
        unordered_map<int, int> bPath; // Stores Time wrt node
        int ans = INT_MIN;

        // Get Bob's path to the 0th node along with time
        findBobPath(bob, 0, bVis, bPath, graph);

        vector<int> aVis(n, 0); // Remembers visiting path for Alice

        // Stores node, time, profit in a queue
        queue<vector<int>> q;
        q.push({0, 0, 0});

        while (!q.empty())
        {

            // Extracting details
            int node = q.front()[0];
            int time = q.front()[1];
            int profit = q.front()[2];

            // Current node is visited
            aVis[node] = 1;
            q.pop();

            // If Bob visited the current node
            if (bPath.find(node) != bPath.end())
            {

                // Bob visited when Alice visited (simultaneously)
                if (bPath[node] == time)
                    profit += amount[node] / 2;

                // Bob visited after Alice
                else if (bPath[node] > time)
                    profit += amount[node];

                // Bob visited before Alice makes amount 0
                // Profit remains same
            }

            // Bob not visited the current node
            else
                profit += amount[node];

            // Explore all neighbors
            for (auto nei : graph[node])
            {

                // If node not visited
                if (!aVis[nei])
                    q.push({nei, time + 1, profit});
            }

            // Update maximum profit when it is leaf node
            if (graph[node].size() == 1 && node != 0)
                ans = max(ans, profit);
        }

        return ans;
    }
};