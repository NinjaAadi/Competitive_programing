#include <bits/stdc++.h>

using namespace std;

//Recurssive

class Solution {
   public:
    vector<vector<int>> dp;
    int findmax(int i, int weightleft, int w[], int val[], int n) {
        if (i >= n) return 0;

        if (dp[i][weightleft] != -1) return dp[i][weightleft];
        //we can take the current element or cannot take the current element
        int take = 0;
        if (weightleft - w[i] >= 0)
            take = val[i] + findmax(i + 1, weightleft - w[i], w, val, n);
        int cant_take = findmax(i + 1, weightleft, w, val, n);

        return dp[i][weightleft] = max(take, cant_take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        dp.resize(n, vector<int>(W + 1, -1));
    }
};

//Iterative

class Solution {
   public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                //if we take
                if (j - wt[i - 1] >= 0)
                    dp[i][j] = val[i - 1] + dp[i - 1][j - wt[i - 1]];

                //if we do not take
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        return dp[n][W];
    }
};