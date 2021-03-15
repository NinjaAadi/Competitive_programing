#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int n = 10e5;
ll Modinv[n];
//Using modulo exponentiation
ll binpow(ll base, ll power) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res = ((res % mod) * (base % mod)) % mod;
        base = ((base * base) % mod);
        power = power >> 1;
    }
    return res % mod;
}
//Using extended euclid algorithm
ll extended(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll ans = extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - floor(a / b) * y1;
    return ans;
}
//Program to calulate modulo multlipicaive inverse using dynammic programming
void calc() {
    Modinv[0] = Modinv[1] = 1;
    for (int i = 2; i < n; i++) {
        Modinv[i] = (Modinv[mod % i] * (-(mod / i))) % mod;
        Modinv[i] = (Modinv[i] + mod) % mod;
    }
}
int main() {
    long long m = binpow(3, mod - 2);
    cout << m << endl;
    long long x, y;
    m = extended(3, mod, x, y);
    if (x < 0) {
        x = (x % mod + mod) % mod;
    }
    cout << x << endl;
    calc();
    cout << Modinv[3] << "\n";
}