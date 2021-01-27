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

void print(vector<int> &k) {
    for (int i : k) {
        cout << i << " ";
    }
    cout << endl;
}

void solve() {
    //0x7ffee915f6ec
    //data type * p = &x;
    //& is used to get the address
    int x = 10;  //Define
    int *p = &x;
    cout << p << endl;
    cout << (*p) << endl;
    int arr[8];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << *(arr + 1) << endl;
    int res[10];
    //malloc() allocates the size of certain memory of your choice
    // int *res = (int *)malloc(sizeof(int) * 10);  //C/C++
    // int *res = new int[10];                      //C++
    // free(res);
    //int arr[n];//INT_MAX = 2147483647

    //int res[n]; //Stack
    // int *res2 = new int[n]; //Heap
    //After word
    // delete[] arr;
    cout << INT_MAX << endl;
    vector<int> k;
    k.push_back(1);
    k.push_back(2);
    print(k);
    // delete[] res2;
}
int main() {
    IOS;
    solve();
    return 0;
}