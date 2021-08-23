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

void input(vector<ll>& arr, int n) {
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
void print(vector<int>& arr) {
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
//build the sparce table
void build(ll n, vector<ll>& arr, vector<vector<ll>>& sparce) {
    for (ll i = 0; i < n; i++) {
        sparce[i][0] = arr[i];
    }
    for (ll j = 1; j <= log2(n); j++) {
        for (ll i = 0; i + (1 << (j - 1)) < n; i++) {
            sparce[i][j] = gcd(sparce[i][j - 1], sparce[i + (1 << (j - 1))][j - 1]);
        }
    }
}
//logn query
ll query(ll l, ll r, vector<vector<ll>>& sparce) {
    ll diff = r - l + 1;
    ll s = l;
    ll ans = 0;
    for (ll i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            //cout << s << " " << i << "\n";
            ans = gcd(ans, sparce[s][i]);
            s += (1 << i);
        }
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr;
    input(arr, n);
    ll ans = 0;

    vl diff;
    for (ll i = 1; i < n; i++) {
        diff.pb(abs(arr[i] - arr[i - 1]));
    }
    vector<vector<ll>> sparce(n + 3, vector<ll>(35, 0));
    build(diff.size(), diff, sparce);

    ll j = 0;
    for (ll i = 0; i < diff.size(); i++) {
        if (i > j) {
            j = i;
        }
        while (j < diff.size() && query(i, j, sparce) > 1) j++;
        //whatis2(i, j);
        j--;
        ans = max(ans, j - i + 1);
    }
    cout << ans + 1 << "\n";
}
int main() {
    IOS;
    testcase {
        solve();
    }
    return 0;
}