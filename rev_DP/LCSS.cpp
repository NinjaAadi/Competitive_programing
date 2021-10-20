#include <bits/stdc++.h>

using namespace std;
class Solution {
   public:
    int longestCommonSubstr(string s1, string s2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp[n][m];
    }
};

//recurssive

class Solution {
   public:
    int mx = 0;
    vector<vector<int>> dp;
    int find(int i, int j, string &s1, string &s2) {
        if (i == s1.size() || j == s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            int curr = 1 + find(i + 1, j + 1, s1, s2);
            mx = max(mx, curr);
            dp[i][j] = curr;
        } else {
            dp[i][j] = 0;
        }
        int first = find(i + 1, j, s1, s2);
        int second = find(i, j + 1, s1, s2);
        return dp[i][j];
    }
    int longestCommonSubstr(string s1, string s2, int n, int m) {
        dp.resize(n + 1, vector<int>(m + 1, -1));
        find(0, 0, s1, s2);
        return mx;
    }
};
