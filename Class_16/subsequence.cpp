#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O2")

typedef long long ll;
typedef unsigned long long ull;
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
#define all(x) x.begin(), x.end(),
#define pb push_back
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
#define in(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define print(arr, n)            \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;

vector<vector<int>> subsequence;
bool cust(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}
void generateallsubsequence(vector<int>& arr, int i, vector<int> temp) {
    //Base Case
    if (i >= arr.size()) {
        return;
    }
    //We have two options
    //When we do not take
    generateallsubsequence(arr, i + 1, temp);

    //When we take
    temp.push_back(arr[i]);
    subsequence.pb(temp);
    generateallsubsequence(arr, i + 1, temp);
}

void solve() {
    vector<int> arr;
    for (int i = 1; i <= 5; i++) {
        arr.pb(i);
    }
    vector<int> temp;
    generateallsubsequence(arr, 0, temp);
    sort(subsequence.begin(), subsequence.end(), cust);
    for (vector<int> i : subsequence) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main() {
    IOS;
    solve();

    return 0;
}