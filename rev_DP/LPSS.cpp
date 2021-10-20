#include <bits/stdc++.h>

using namespace std;

//Recurssive
class Solution {
   public:
    string res = "";
    vector<vector<string>> dp;
    string find(int l, int r, string &s) {
        if (l > r) return "";
        if (l == r) {
            string tt = "";
            tt += s[l];
            if (tt.size() > res.size()) res = tt;
            return tt;
        }
        if (dp[l][r].size() > 0) return dp[l][r];
        if (s[l] == s[r]) {
            string mid = find(l + 1, r - 1, s);
            //cout<<l<<" "<<r<<" "<<mid<<endl;
            if (mid != "-1") {
                mid = s[l] + mid;
                mid += s[r];
                if (mid.size() > res.size()) res = mid;
                dp[l][r] = mid;
            } else {
                dp[l][r] = "-1";
            }
        } else {
            dp[l][r] = "-1";
        }
        string c1 = find(l + 1, r, s);
        string c2 = find(l, r - 1, s);
        return dp[l][r];
    }
    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n, vector<string>(n, ""));
        find(0, s.size() - 1, s);
        return res;
    }
};

//Iterative
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));
        string mx = "";
        for (int x = 0; x < n; x++) {
            for (int y = 0; y <= (n - x - 1); y++) {
                int i = y;
                int j = y + x;
                if (i == j) {
                    dp[i][j] = s[i];
                    if (dp[i][j].size() > mx.size()) mx = dp[i][j];
                    continue;
                } else if (i + 1 == j) {
                    if (s[i] == s[j]) {
                        dp[i][j] += s[i];
                        dp[i][j] += s[j];
                        if (dp[i][j].size() > mx.size()) mx = dp[i][j];
                        continue;
                    }
                }
                if (s[i] == s[j]) {
                    if (dp[i + 1][j - 1] != "") {
                        string res = "";
                        res += s[i];
                        res += dp[i + 1][j - 1];
                        res += s[j];
                        dp[i][j] = res;
                        if (dp[i][j].size() > mx.size()) mx = dp[i][j];
                    }
                }
            }
        }
        return mx;
    }
};

