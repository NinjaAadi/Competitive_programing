class Solution {
   public:
    vector<vector<int>> dp;
    int find(int l, int r, int *arr, int n) {
        if (l + 1 == r) return 0;
        int ans = INT_MAX;
        if (dp[l][r] != -1) return dp[l][r];
        for (int i = l + 1; i < r; i++) {
            int curr = find(l, i, arr, n) + find(i, r, arr, n);
            curr += (arr[l] * arr[i] * arr[r]);
            ans = min(ans, curr);
        }
        return dp[l][r] = ans;
    }
    int matrixMultiplication(int n, int arr[]) {
        // code here
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return find(0, n - 1, arr, n);
    }
};