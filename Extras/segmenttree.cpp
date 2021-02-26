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

using namespace std;
const int N = 2e6;
ll tree[N];

void buildtree(ll arr[], ll n, ll ind, ll l, ll r) {
    if (l == r) {
        tree[ind] = arr[l];
        return;
    }
    ll m = (l + r) / 2;
    buildtree(arr, n, 2 * ind, l, m);
    buildtree(arr, n, 2 * ind + 1, m + 1, r);
    tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
}
void query(ll arr[], ll ql, ll qr, ll tl, ll tr, ll &ans, ll ind) {
    //Completely overlapping
    if (tl >= ql && tr <= qr) {
        ans = min(ans, tree[ind]);
        return;
    }
    //Completely out
    if (tl > qr || tr < ql) {
        return;
    }

    ///Partially overlaps
    ll m = (tl + tr) / 2;
    query(arr, ql, qr, tl, m, ans, 2 * ind);
    query(arr, ql, qr, m + 1, tr, ans, 2 * ind + 1);
}
void pointupdate(ll pos, ll val, ll tl, ll tr, ll ind) {
    if (tl == tr) {
        tree[ind] = val;
        return;
    }
    ll m = (tl + tr) / 2;
    if (pos >= tl && pos <= m) {
        pointupdate(pos, val, tl, m, 2 * ind);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
    } else {
        pointupdate(pos, val, m + 1, tr, 2 * ind + 1);
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
    }
}
void rangeupdate(ll val, ll tl, ll tr, ll ql, ll qr, ll ind) {
    if (tl == tr) {
        tree[ind] += val;
        return;
    }
    if (tr < ql || tl > qr) return;
    ll m = (tl + tr) / 2;
    rangeupdate(val, tl, m, ql, qr, 2 * ind);
    rangeupdate(val, m + 1, tr, ql, qr, 2 * ind + 1);
    tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}

void solve() {
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(tree, 0, sizeof(tree));
    buildtree(arr, n, 1, 0, n - 1);
    while (q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            pointupdate(b, c, 0, n - 1, 1);
        } else {
            ll ans = INT_MAX;
            b--;
            c--;
            query(arr, b, c, 0, n - 1, ans, 1);
            cout << ans << "\n";
        }
    }
}
int main() {
    IOS;
    solve();
    return 0;
}