#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Solve(vector<int>& values, int i, int j, vector<vector<int>> &dp) // yeha pe dp[i][j] ka matlab hai ki i se j tak ka minimum score
    {
        if (i + 1 == j) // agar i + 1 == j hai toh koi triangle nahi banega
            return 0;
        
        if (dp[i][j] != -1) // agar dp[i][j] != -1 hai toh hume answer mil gaya hai
            return dp[i][j];

        int ans = INT_MAX; // yeha pe hume minimum score nikalna hai
        for (int k = i + 1; k < j; k++) // yeha pe hume i se j tak ka minimum score nikalna hai
        {
            ans = min(ans, values[i] * values[j] * values[k] + Solve(values, i, k,dp) + Solve(values, k, j,dp)); // yeha pe hume i se k tak ka minimum score aur k se j tak ka minimum score nikalna hai
        }

        dp[i][j] = ans; // yeha pe hume dp[i][j] ko ans se update karna hai
        return dp[i][j]; // yeha pe hume dp[i][j] return karna hai
    }

    int minScoreTriangulation(vector<int>& values)
    {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        return Solve(values, 0, values.size() - 1,dp);
    }
};