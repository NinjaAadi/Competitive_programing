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

void input(vector<int>& arr, int n) {
    arr.resize(n);
    loop(i, n) {
        cin >> arr[i];
    }
}
void input2(vector<vector<int> >& arr, int n, int m) {
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
void print2(vector<vector<int> >& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int rangeRandom(int min, int max) {
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}
int n, m;
bool isrange(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}
bool check(int l1, int r1, int l2, int r2) {
    if (!isrange(l1, r1) || !isrange(l2, r2)) return false;
    return l1 <= l2 && r1 <= r2;
}
void solve() {
    srand(time(NULL));
    n = 1000;
    m = 1000;
    cout << n << " " << m << endl;
    int q = 10000;
    cout << q << "\n";
    for (int i = 0; i <= q; i++) {
        int l1 = rangeRandom(1, n);
        int r1 = rangeRandom(1, m);
        int l2 = rangeRandom(l1, n);
        int r2 = rangeRandom(r1, m);
        while (check(l1, r1, l2, r2) == false) {
            l1 = rangeRandom(1, n);
            r1 = rangeRandom(1, m);
            l2 = rangeRandom(l1, n);
            r2 = rangeRandom(r1, m);
        }
        int k = rand() % 10000;
        if (i == q)
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        else
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << " " << k << "\n";
    }
}
int main() {
    IOS;
    solve();
    return 0;
}