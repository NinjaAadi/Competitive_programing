#include <bits/stdc++.h>

#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define MOD 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
#define input(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i]
#define print(arr, n)            \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;
ll prefix[33][200005];

void solve() {
    ll n, q;
    cin >> n >> q;
    //Idea is to use prefix array for 20 bits;
    ll arr[n];
    input(arr, n);
    memset(prefix, 0, sizeof(prefix));
    for (int i = 0; i <= 32; i++) {
        ll po = (1LL << i);
        if (arr[0] & po) {
            prefix[i][0] = 1;
        }
        for (ll j = 1; j < n; j++) {
            if (arr[j] & po) {
                prefix[i][j]++;
            }
            prefix[i][j] += prefix[i][j - 1];
        }
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll sum = 0;
        for (int i = 0; i <= 32; i++) {
            ll numcount;
            if (l == 0) {
                numcount = prefix[i][r];
            } else {
                numcount = prefix[i][r] - prefix[i][l - 1];
            }
            if (numcount == 0)
                continue;
            else if (numcount % 2 != 0) {
                sum += (ll)((1LL << i));
            }
        }
        cout << sum << "\n";
    }
}
int main() {
    IOS;
    solve();
    return 0;
}