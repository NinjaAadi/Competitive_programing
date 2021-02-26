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
    ll arr[n];
    loop(i, n) {
        cin >> arr[i];
    }
    ll prefix[n];
    memset(prefix, 0, sizeof(prefix));
    prefix[0] = arr[0];

    //Make the prefix array of xor sum
    for (ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] ^ arr[i];
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0) {
            cout << prefix[r] << "\n";
            continue;
        }
        ll x1 = prefix[r];
        ll x2 = prefix[l - 1];
        ll ans = x1 ^ x2;
        cout << ans << "\n";
    }

    for (int i = 0; i <= 32; i++) {
        if (arr[i] & (1 << i)){
            //The ith bit of arr[i] is 1
        }
        else {
            //The ith bit of arr[i] is 0
        }
    }
}
int main() {
    IOS;
    solve();
    return 0;
}