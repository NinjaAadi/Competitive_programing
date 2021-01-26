#include <bits/stdc++.h>

#include <map>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define MOD 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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

using namespace std;

int main() {
    IOS;
    map<int, int> m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(3, 2));
    m.insert(make_pair(4, 1));
    m[7] = 10;
    for (pair<int, int> p : m) {
        cout << p.first << " " << p.second << endl;
    }
    map<string, vector<int> > name;
    name["aaditya"].push_back(1);
    name["aaditya"].push_back(2);
    name["aaditya"].push_back(3);
    for (pair<string, vector<int> > p : name) {
        cout << p.first << " ";
        for (int i : p.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}