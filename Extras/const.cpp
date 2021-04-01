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
#define print(arr, n)            \
    for (ll i = 0; i < n; i++) { \
        cout << arr[i] << " ";   \
    }                            \
    cout << "\n";
using namespace std;
class Animal {
   public:
    string name;
    Animal(const string &i) {
        //i = "Cat";// now we cannot do this because we are taking the reference of the variable as constant
        this->name = i;
    }
    //return a const value means we cannot modify the value that we are sending
    const string &getname() {
        return this->name;
    }
    void printname() const{
        //this->name = "Mouse\n"; we cannot change the class variable in the const functions : -)
    }
};
void solve() {
    int x = 10;
    int y = 20;
    const int *p = &x;  //
    //*p = *p + 1; //Cannot change the data but can change the poiner
    p = &y;
    cout << *p << endl;
    int *const p2 = &x;  //Pointer is constant and the data can be changed
    *p2 = 5;
    cout << x << endl;

    //Lets now see that what can we do with const keyword in functions
    string s = "Dog";
    Animal *a1 = new Animal(s);
    cout << a1->name << endl;
    const string &ss = a1->getname();  //we can recieve via reference but if we use const keyword we cannot change the value
    //ss = "Cat";
    cout << ss << endl;
    cout << a1->name << endl;
}
int main() {
    IOS;
    solve();
    return 0;
}