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
const int N = 2e5 + 1;
ll prefix[N];

//Time to precompute (O(n));
void calculate(int arr[], int n) {
    memset(prefix, 0, sizeof(prefix));  //Safe
    for (int i = 0; i < n; i++) {
        if (i != 0)
            prefix[i] = prefix[i - 1] + arr[i];
        else
            prefix[i] = arr[i];
    }
}
//Time to query (O(1));
ll query(int l, int r) {
    return (l == 0) ? (prefix[r]) : (prefix[r] - prefix[l - 1]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    loop(i, n) {
        cin >> arr[i];
    }
    calculate(arr, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(l, r) << "\n";
    }
}
int main() {
    IOS;
    solve();
    return 0;
}