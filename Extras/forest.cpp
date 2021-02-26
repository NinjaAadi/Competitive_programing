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

void solve() {
    ll n, q;
    cin >> n >> q;
    int mat[n + 1][n + 1];
    memset(mat, 0, sizeof(mat));
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < n; j++) {
            if (s[j] == '.') {
                mat[i + 1][j + 1] = 0;
            } else {
                mat[i + 1][j + 1] = 1;
            }
        }
    }

    //Create the prefix array
    ull prefix[n + 1][n + 1];
    memset(prefix, 0, sizeof(prefix));
    prefix[1][1] = mat[1][1];
    for (ull i = 2; i <= n; i++) {
        prefix[i][1] += (mat[i][1] + prefix[i - 1][1]);
        prefix[1][i] += (mat[1][i] + prefix[1][i - 1]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            prefix[i][j] += (prefix[i - 1][j] + prefix[i][j - 1] + mat[i][j] - prefix[i - 1][j - 1]);
        }
    }

    while (q--) {
        ull x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ull ans = prefix[x2][y2] - (prefix[x1 - 1][y2] + prefix[x2][y1 - 1]) + prefix[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
}
int main() {
    IOS;
    solve();
    return 0;
}