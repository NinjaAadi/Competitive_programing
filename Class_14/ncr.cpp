#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e5;
const int M = 1e9 + 7;
ll fact[N + 5];
ll inv[M + 1];
void init() {
    fact[0] = 1;
    fact[1] = 1;
    inv[1] = 1;
    inv[0] = 1;
    for (int i = 2; i <= N; i++) {
        fact[i] = ((fact[i - 1]) % M * (i % M)) % M;
    }
    for (int i = 2; i <= M; i++) {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }
}
ll ncr(ll n, ll r) {
    if (r > n) {
        return 0;
    }
    ll res = fact[n];
    ll base = (fact[n - r] * fact[r]) % M;
    cerr << base << endl;
    cerr << inv[base] << endl;
    return res;
}
int main() {
    init();
    cout << ncr(9998, 12) << endl;
}