/*
    207. Course Schedule
    TC: O(V + E) [Every node has a single edge]
    SC: O(2N)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {

        // Current node is visited
        vis[node] = 1;

        // Current node is considered as visiting path
        pathVis[node] = 1;

        // Explore all neighbors
        for (auto it : adj[node])
        {

            // If node not visited
            if (!vis[it])
            {

                // Visit node to detect cycle
                if (!dfsCheck(it, adj, vis, pathVis))
                    return false; // Cycle exists
            }

            // If a node is re-visiting itself in the same path - cycle
            else if (pathVis[it])
                return false; // Cycle exists
        }

        // Backtrack
        pathVis[node] = 0;

        // No cycle
        return true;
    }

public:
    // Main
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];
        vector<int> vis(numCourses, 0);     // Visited path
        vector<int> pathVis(numCourses, 0); // Remembers visiting path

        // Adjacency List
        for (auto it : prerequisites)
        {

            adj[it[1]].push_back(it[0]);
        }

        // For each node try to find cycle
        for (int i = 1; i < numCourses; i++)
        {

            // If node not visited
            if (!vis[i])
            {

                // Visit node to detect cycle
                if (!dfsCheck(i, adj, vis, pathVis))
                    return false; // Cycle exists
            }
        }
        return true;
    }
};

/*
    Approach:
    Detect cycle in a directed graph using DFS
*/