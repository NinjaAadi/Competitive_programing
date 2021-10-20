

long long find(long long l, long long r, vector<int> &arr, vector<vector<long long>> &dp, vector<vector<long long>> &ind) {
    if (r - l <= 1) return 0;
    long long mx = 1e9;
    long long id;
    if (dp[l][r] != -1) return dp[l][r];
    for (long long i = l + 1; i < r; i++) {
        long long curr = arr[r] - arr[l] + find(l, i, arr, dp, ind) + find(i, r, arr, dp, ind);
        if (curr < mx) {
            id = i;
            mx = curr;
        }
    }
    ind[l][r] = id;
    return dp[l][r] = mx;
}
vector<long long> res;

void findid(long long l, long long r, vector<int> &arr, vector<vector<long long>> &ind) {
    if (r - l <= 1) return;
    res.push_back(arr[ind[l][r]]);
    findid(l, ind[l][r], arr, ind);
    findid(ind[l][r], r, arr, ind);
}
vector<int> Solution::rodCut(int n, vector<int> &arr) {
    res.clear();
    arr.push_back(0);
    arr.push_back(n);
    sort(arr.begin(), arr.end());
    vector<vector<long long>> dp(arr.size(), vector<long long>(arr.size(), -1));
    vector<vector<long long>> indices(arr.size(), vector<long long>(arr.size()));
    long long curr = find(0, arr.size() - 1, arr, dp, indices);
    findid(0, arr.size() - 1, arr, indices);
    return res;
}