#include <bits/stdc++.h>

#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cerr << #x << " = " << x << endl;
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
#define in(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define print(arr, n)            \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;
struct Query {
    ll l;
    ll r;
    ll ans;
    ll index;
};
int bs = 555;

//Compare function to speed up the Mo's algorithm by a constant factor
bool comp(Query q1, Query q2) {
    if (q1.l / bs != q2.l / bs) {
        return q1.l < q2.l;
    }
    if ((q1.l / bs) & 1) {
        return q1.r < q2.r;
    } else {
        return q1.r > q2.r;
    }
}
bool comp1(Query q1, Query q2) {
    return q1.index < q2.index;
}

//Execute mos algorithm
void mos(ll arr[], Query q[], ll n, ll qs) {
    ll feq[200005];
    memset(feq, 0, sizeof(feq));
    ll ans = 0;
    //Initialize with the first query
    ll bl = q[0].l;
    ll br = q[0].r;
    for (ll i = bl; i <= br; i++) {
        feq[arr[i]]++;
        if (feq[arr[i]] == 1) {
            ans++;
        }
    }
    q[0].ans = ans;
    for (ll i = 1; i < qs; i++) {
        ll l = q[i].l;
        ll r = q[i].r;
        for (ll i = l; i < bl; i++) {
            feq[arr[i]]++;
            if (feq[arr[i]] == 1) {
                ans++;
            }
        }
        for (ll i = l - 1; i >= bl; i--) {
            feq[arr[i]]--;
            if (feq[arr[i]] == 0) {
                ans--;
            }
        }
        for (ll i = r; i > br; i--) {
            feq[arr[i]]++;
            if (feq[arr[i]] == 1) {
                ans++;
            }
        }
        for (ll i = r + 1; i <= br; i++) {
            feq[arr[i]]--;
            if (feq[arr[i]] == 0) {
                ans--;
            }
        }
        bl = q[i].l;
        br = q[i].r;
        q[i].ans = ans;
    }
}

void solve() {
    ll n, Q;
    cin >> n >> Q;
    ll arr[n];
    map<int, int> coordinateCompress;
    int compressed_Num = 1;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (coordinateCompress.find(arr[i]) != coordinateCompress.end()) {
            arr[i] = coordinateCompress[arr[i]];
        } else {
            coordinateCompress[arr[i]] = compressed_Num;
            arr[i] = compressed_Num++;
        }
    }
    struct Query q[Q];
    for (ll i = 0; i < Q; i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        q[i].l = l;
        q[i].r = r;
        q[i].ans = 0;
        q[i].index = i;
    }

    sort(q, q + Q, comp);
    mos(arr, q, n, Q);
    sort(q, q + Q, comp1);
    for (int i = 0; i < Q; i++) {
        cout << q[i].ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}