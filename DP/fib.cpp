#include <bits/stdc++.h>

#include <unordered_map>
#pragma GCC optimize("O2")

typedef long long ll;
typedef unsigned long long ull;
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
#define all(x) x.begin(), x.end(),
#define pb push_back
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
#define in(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define print(arr, n)            \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;

//Top down dp
ll findfib(ll n, vector<ll> &dp) {
    if (n <= 1) return dp[n] = n;
    if (dp[n] != -1) return dp[n];
    dp[n] = findfib(n - 1, dp) + findfib(n - 2, dp);
    return dp[n];
}

int main() {
    ll n;
    cin >> n;
    // printfib(0, 1, 1, n);
    // cout << endl;
    vector<ll> dp(n + 1, -1);
    cout << findfib(n, dp) << endl;
    print(dp, n + 1);
    dp.assign(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    print(dp, n + 1);
}
// n = 0;
// ans = 0;
// n = 1;
// ans = 1;
// n = 2 dp[n - 1] + dp[n - 2];
// n = 3 dp[n-1] + dp[n-2];
// n = 4 dp[3]  + d[2];