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

using namespace std;
const int N = 2e5 + 5;
ull n, q;
ull arr[N];
ull tree[5 * N];
ull lazy[5 * N];

//Initialize the arrays
void init() {
    memset(arr, 0, sizeof(arr));
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
}
//Function to build the segment tree
void buildtree(ull l, ull r, ull ind) {
    //Base case
    if (l == r) {
        tree[ind] = arr[l];
        return;
    }
    ull m = (l + r) / 2;
    buildtree(l, m, 2 * ind);
    buildtree(m + 1, r, 2 * ind + 1);
    tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}

//Function for lazy updation
void lazyupdate(ull ind, ull l, ull r, ull ql, ull qr, ull val) {
    //If there is some pending update then do it first
    if (lazy[ind] != 0) {
        tree[ind] += (ull)((r - l + 1) * (lazy[ind]));
        if (l != r) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    //If tree is out of range
    if (l > qr || r < ql) return;

    //If tree is completely in range then update and add the rest to the lazy
    if (l >= ql && r <= qr) {
        tree[ind] += val * (r - l + 1);
        lazy[2 * ind] += val;
        lazy[2 * ind + 1] += val;
        return;
    }

    //If the tree is partially in range then recur for its childres
    ull m = (l + r) / 2;
    lazyupdate(2 * ind, l, m, ql, qr, val);
    lazyupdate(2 * ind + 1, m + 1, r, ql, qr, val);
    tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}
//Function for lazy query
ull lazyquery(ull ind, ull ql, ull qr, ull l, ull r) {
    //If there is some pending update then do it first
    if (lazy[ind] != 0) {
        tree[ind] += (ull)((r - l + 1) * lazy[ind]);
        if (l != r) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    //If tree is out of range
    if (l > qr || r < ql) return 0;

    //If the tree completely overlaps
    if (l >= ql && r <= qr) {
        return tree[ind];
    }

    //If the tree partially overlaps then recurr for the childs and then return the sum of its children
    ull m = (l + r) / 2;
    ull sum = 0;
    sum += lazyquery(2 * ind, ql, qr, l, m);
    sum += lazyquery(2 * ind + 1, ql, qr, m + 1, r);
    return sum;
}
void solve() {
    init();
    cin >> n >> q;
    for (ull i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildtree(0, n - 1, 1);
    while (q--) {
        int a;
        cin >> a;
        if (a == 1) {
            ull l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            lazyupdate(1, 0, n - 1, l, r, val);
        } else {
            ull k;
            cin >> k;
            cout << lazyquery(1, k - 1, k - 1, 0, n - 1) << "\n";
        }
    }
}
int main() {
    IOS;
    solve();
    return 0;
}