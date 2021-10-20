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
string s1, s2;
// s1 - > s2
vector<vector<int>> dp;
int find(int i, int j) {
    //Base cases
    if (i == s1.size()) {
        return s2.size() - j;
    }
    if (j == s2.size()) {
        return s1.size() - i;
    }
    if (dp[i][j] != -1) return dp[i][j];
    //add remove replace
    int ans = 0;
    if (s1[i] == s2[j]) {
        ans = find(i + 1, j + 1);
    } else {
        //if remove
        int a = 1 + find(i + 1, j);

        //if replace
        int b = 1 + find(i + 1, j + 1);

        //if add
        int c = 1 + find(i, j + 1);
        ans = min(a, min(b, c));
    }
    return dp[i][j] = ans;
}
void solve() {
    cin >> s1 >> s2;
    dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << find(0, 0) << "\n";
}
int main() {
    IOS;
    solve();
    return 0;
}