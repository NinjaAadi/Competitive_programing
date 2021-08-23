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

vector<int> weight;
vector<int> value;
int n;
int W;
int findmin(int id, int we) {
    //Base case
    if (id >= weight.size()) return 0;
    //can we take
    int ans = 0;
    if (we + weight[id] <= W) {
        ans = max(ans, value[id] + findmin(id + 1, we + weight[id]));
    }
    //cannot take
    ans = max(ans, 0 + findmin(id + 1, we));
    return ans;
}
void solve() {
    cin >> n;
    cin >> W;

    weight.resize(n);
    value.resize(n);
    loop(i, n) {
        cin >> weight[i];
    }
    loop(i, n) {
        cin >> value[i];
    }
    cout << findmin(0, 0) << "\n";
}
int main() {
    IOS;
    testcase {
        solve();
    }
    return 0;
}