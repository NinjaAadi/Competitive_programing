#include <bits/stdc++.h>

using namespace std;

//Reccurssive
class Solution {
   public:
    vector<vector<int>> dp;
    int find(int i, int j, string &s1, string &s2) {
        if (i == s1.size() || j == s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + find(i + 1, j + 1, s1, s2);
        } else {
            return dp[i][j] = max(find(i + 1, j, s1, s2), find(i, j + 1, s1, s2));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        dp.resize(s.size(), vector<int>(s.size(), -1));
        reverse(s2.begin(), s2.end());
        return find(0, 0, s, s2);
    }
};

//Iterative
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string s1 = s;
        reverse(s1.begin(), s1.end());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s1[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};
