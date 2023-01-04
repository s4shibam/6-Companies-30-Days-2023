/*
    391. Perfect Rectangle
    TC: O(N)
    SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {

        // Maps all points to a respective calculation. If it is a valid rectangle,
        // all interior points should have count 0, bottom left most and top right
        // most point should have value 1, and top left and bottom right should have
        // count -1. If it is different than this, it is not a perfect rectangle.
        pair<pair<int, int>, int> vertex;

        for (auto rec : rectangles)
        {

            // Bottom Left Vertex -->(x1, y1)
            vertex[{rec[0], rec[1]}]++;

            // Top Left Vertex -->(x1, y2)
            vertex[{rec[0], rec[3]}]--;

            // Top Right Vertex -->(x2, y2)
            vertex[{rec[2], rec[3]}]++;

            // Bottom Right Vertex -->(x2, y1)
            vertex[{rec[2], rec[1]}]--;
        }

        int restVertex = 0;

        for (auto it : vertex)
        {

            // If any vertex is available, count it
            if (it.second != 0)
            {

                // Value of overlapping Vertexes must be
                // less than -1 or, greater than 1, so rectangle is invalid
                if (abs(it.second) != 1)
                    return false;

                restVertex++;
            }
        }

        // Count for all the available vertexes must be 4 to be a valid big rectangle
        return restVertex == 4;
    }
};

/*
Intuition
If it is a valid rectangle,
all interior points should have count 0,
bottom left most and top right most point should have value 1,
and top left and bottom right should have count -1.
If it is different than this, it is not a perfect rectangle.
*/