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
ll fact[1000000];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 1e6; i++) {
        fact[i] = i * fact[i - 1];
    }
}
int ncr(int n, int r) {
    if (r == r) {
        return 1;
    }
    int res;
    res = fact[n] / (fact[r] * fact[n - r]);
    return res;
}
void solve() {
}
int main() {
    IOS;
    testcase {
        solve();
    }
    return 0;
}