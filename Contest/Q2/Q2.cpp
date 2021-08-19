#include <bits/stdc++.h>

#include <unordered_map>

#pragma GCC optimize("O2")

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define MOD 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
typedef vector<int> vi;

void input(vector<int>& arr, int n) {
    arr.resize(n);
    loop(i, n) {
        cin >> arr[i];
    }
}
void input2(vector<vector<int>>& arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}
void print(vector<char>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print2(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<char> pp;
char find(char curr, int k) {
    int c = curr - 'a';
    if (c - k < 0) {
        return pp[c + 26 - k];
    }
    return pp[c - k];
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    vi dp(26, 0);
    dp[s[0] - 'a'] = cost[0];
    k %= 26;
    // whatis(s);
    for (int i = 1; i < n; i++) {
        int curr = s[i] - 'a';
        char nc = find(s[i], k);
        int nk = nc - 'a';
        dp[curr] = max(dp[curr], cost[i] + dp[nk]);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
int main() {
    IOS;
    for (int i = 0; i < 26; i++) {
        pp.pb(i + 'a');
    }
    for (int i = 0; i < 26; i++) {
        pp.pb(i + 'a');
    }
    testcase {
        solve();
    }
    return 0;
}