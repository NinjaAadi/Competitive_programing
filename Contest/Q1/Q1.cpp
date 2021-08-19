/*
You are given N candies(c1,c2,c3,c4...cn) in a bucket which have different size.


You are allowed to eat candies in alternate ways
    1st step : Take the maximum size candy, eat half of the candy and put the remaining candy into the bucket.
    2nd step : Take the minimum size candy, eat half of the candy and put the remaining candy into the bucket.

If any time the size of candy is 1 or 2, you eat whole of the candy without i.e skip the insertion part
You always start with the first step

Find the minimum number of steps in which you can finish all the candies


*/
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
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    bool first = true;
    long long op = 0;
    while (s.size() > 0) {
        if (first) {
            auto curr = s.end();
            curr--;
            int t = *curr;
            s.erase(curr);
            if (t <= 2) {
            } else {
                s.insert(t / 2);
            }
            op++;
        } else {
            auto curr = s.begin();
            int t = *curr;
            s.erase(curr);
            if (t <= 2) {
            } else {
                s.insert(t / 2);
            }
            op++;
        }
        first = (first) ? (false) : (true);
    }
    cout << op << "\n";
}
int main() {
    IOS;
    solve();
    return 0;
}