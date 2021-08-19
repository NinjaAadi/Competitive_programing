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

void solve() {
    int t = 10;
    srand(time(0));
    cout << t << endl;
    while (t--) {
        int n = 100000;
        int k = rand() % 100000;
        cout << n << " " << k << endl;
        string res = "";
        vi cost(n);
        for (int i = 0; i < n; i++) {
            if (t == 100)
                cost[i] = 1;
            else
                cost[i] = rand() % 1000 + 1;
        }
        for (int i = 0; i < n; i++) {
            int curr = rand() % 26;
            res += (curr + 'a');
        }
        cout << res << "\n";
        print(cost);
    }
}
int main() {
    IOS;
    solve();
    return 0;
}