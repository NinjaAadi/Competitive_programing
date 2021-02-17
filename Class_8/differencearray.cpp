#include <bits/stdc++.h>

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
/*
e = 1 2 3 4 5 6 7 8
i = 0 1 2 3 4 5 6 7
0-5 +5
0-3 -3
1-4 +10
difference array
0 1 2 3 4 5 6
5 0 0 0 0 0 -5
2 0 0 0 3 0 -5
2 10 0 0 3 -10 -5

difference[i]+=difference[i-1];



Ulitmate
0-1  +2
1-3  +12
3-4  +15
4-5  +5


*/
void solve() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int difference[7];
    memset(difference, 0, sizeof(difference));
    int q;
    cin >> q;
    while (q--) {
        int l, r, w;
        cin >> l >> r >> w;
        difference[l] += w;
        difference[r + 1] -= w;
        for (int i = 0; i < 7; i++) {
            cout << difference[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 7; i++) {
        if(i!=0) difference[i] += difference[i - 1];
        cout << difference[i] << " ";
    }
    cout << endl;
}
int main() {
    IOS;
    testcase {
        solve();
    }
    return 0;
}