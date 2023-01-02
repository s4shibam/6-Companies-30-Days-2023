/*
    150. Evaluate Reverse Polish Notation
    TC: O(N)
    SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Perform operation according to operators
    long long operation(long long a, long long b, string t)
    {

        if (t == "+")
            return a + b;
        else if (t == "-")
            return a - b;
        else if (t == "*")
            return a * b;
        else if (t == "/")
            return a / b;

        return 0;
    }

    // Main
    int evalRPN(vector<string> &tokens)
    {

        stack<long long> post;

        for (auto t : tokens)
        {

            // Pop out last two operands from the stack if 't' is operator, then
            // Perform operation and push the result in the stack
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {

                int b = post.top();
                post.pop();
                int a = post.top();
                post.pop();
                post.push(operation(a, b, t));
            }
            // Push into the stack if 't' is operand
            else
            {

                post.push(stoi(t));
            }
        }

        // return top which is the result
        return post.top();
    }
};