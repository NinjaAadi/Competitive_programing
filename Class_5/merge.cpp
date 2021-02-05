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

void solve() {
    int n1 = 5;
    int n2 = 6;
    int a1[5] = {1, 2, 3, 5, 6};
    int a2[6] = {4, 7, 8, 9, 10, 11};
    // int n = (sizeof(a1) / sizeof(int)) + (sizeof(a2) / sizeof(int));
    int a3[11];
    int i = 0;  //a1
    int j = 0;  //a2
    int k = 0;  //a3
    //while(0)  false
    //while(1)  true
    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            a3[k] = a1[i];
            i++;
        } else if (a2[j] < a1[i]) {
            a3[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a3[k] = a1[i];
        i++;
        k++;
    }
    while (j < n2) {
        a3[k] = a2[j];
        j++;
        k++;
    }
    for (int i = 0; i < 11; i++) {
        cout << a3[i] << " ";
    }
    cout << "\n";
}
int main() {
    IOS;
    solve();
    return 0;
}