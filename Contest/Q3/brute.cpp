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
vector<vector<int> > mat;
int total(int l1, int r1, int l2, int r2) {
    int x = l2 - l1 + 1;
    int y = r2 - r1 + 1;
    return x * y;
}
void update(int l1, int r1, int l2, int r2, int k) {
    int ans = ceil((double)k / (double)total(l1, r1, l2, r2));
    //whatis2(ans, total(l1, r1, l2, r2));
    for (int i = l1; i <= l2; i++) {
        mat[i][r1] += ans;
        mat[i][r2 + 1] -= ans;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    mat.assign(n + 1, vector<int>(m + 3, 0));
    int q;
    cin >> q;
    int l1, l2, r1, r2, k;
    for (int i = 0; i < q; i++) {
        cin >> l1 >> r1 >> l2 >> r2 >> k;
        l1--;
        l2--;
        r1--;
        r2--;
        update(l1, r1, l2, r2, k);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
            } else {
                mat[i][j] += mat[i][j - 1];
            }
        }
    }
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    long long sum = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            sum += mat[i][j];
        }
    }
    cout << sum << "\n";
}
int main() {
    IOS;
    solve();
    return 0;
}