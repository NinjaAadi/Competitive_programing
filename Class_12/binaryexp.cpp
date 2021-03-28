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

ll p(ll a, ll b) {
    ll res = 1;
    for (int i = 0; i < b; i++) {
        res *= b;
    }
}
//Recurssive Function
int power(ll a, ll n) {
    //Base case
    if (n == 1) return a;
    if (n == 0) return 1;

    if (n % 2 == 0) {
        ll res = power(a, n / 2);
        return res * res;
    } else {
        ll res = power(a, n - 1);
        return res * a;
    }
}
//Binary exponentiation iterative
ll power2(ll base, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power % 2 != 0) {
            res = res * base;
            power--;
        } else {
            base = base * base;
            power = power / 2;
        }
    }
    return res;
}
//Code taken from https://cp-algorithms.com/algebra/binary-exp.html
long long binpow(long long a, long long b, long long p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res % p * a % p) % p;
        a = (a % p * a % p) % p;
        b >>= 1;
    }
    return res;
}
ll pp(ll base, ll power) {
    int res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * base;
        }
        base = base * base;
        power = power >> 1;
    }
}
void solve() {
    cout << power2(2, 10) << "\n";
    int p = rand() % 10;
}
int main() {
    IOS;
    solve();
    return 0;
}