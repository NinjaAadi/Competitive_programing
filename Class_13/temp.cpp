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
const int N = 1e6 + 5;
int prime[N];
int prefix[N];
void SieveOfEratosthenes() {
    for (int i = 0; i < N; i++) {
        prime[i] = 1;
    }
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.

    for (int p = 2; p * p < N; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == 1) {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i < N; i += p)
                prime[i] = 0;
        }
    }
}
void init() {
    for (int i = 0; i < N; i++) {
        prefix[i] = 0;
    }
    prefix[0] = 0;
    prefix[1] = 0;
    for (int i = 2; i < N; i++) {
        if (prime[i] == 1) {
            prefix[i] += (1 + prefix[i - 1]);
        } else {
            prefix[i] = prefix[i - 1];
        }
    }
}
void solve() {
    int l, r;
    // cin >> l >> r;
    // if (l == 0) {
    //     cout << prefix[r] << "\n";
    //     return;
    // }
    // cout << prefix[r] - prefix[l - 1] << "\n";
}
int main() {
    IOS;
    SieveOfEratosthenes();
    init();
    whatis(prefix[10]);
    testcase {
        solve();
    }
    return 0;
}