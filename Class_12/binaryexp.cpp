#include <bits/stdc++.h>
#include <unordered_map>
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
#define print(arr, n)           \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;

//Recurssive Function
int power(ll a  , ll n){
    //Base case
    if(n==1) return a;
    if(n==0) return 1;

    if(n%2==0){
        ll res = power(a,n/2);
        return res*res; 
    }
    else{
        ll res = power(a,n-1);  
        return res*a;
    }

}
//Binary exponentiation iterative
ll power2(ll base, ll power){
    ll res = 1;
    while(power > 0){
        if(power%2!=0){
            res = res*base;
            power--;
        }
        else{
            base = base*base;
            power = power/2;
        }
    }
    return res;
}
void solve() {
   cout<<power2(2,10)<<"\n";
}
int main() {
    IOS;
    solve();
    return 0;
}