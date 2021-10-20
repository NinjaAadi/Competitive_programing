//Recurssive
class Solution {
   public:
    vector<vector<int>> dp;
    int findlcs(int i, int j, string &s1, string &s2) {
        if (i == s1.size() || j == s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j])
            dp[i][j] = return 1 + findlcs(i + 1, j + 1, s1, s2);
        else {
            dp[i][j] = return max(findlcs(i + 1, j, s1, s2), findlcs(i, j + 1, s1, s2));
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return findlcs(0, 0, s1, s2);
    }
};

//Iterative
class Solution {
   public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};