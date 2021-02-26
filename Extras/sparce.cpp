//Sparce table for competitive programming
#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

const int N = 2e5 + 2;
ll sparce[N][20];  //Sparce matrix
ll arr[N];         //Array
ll n;              //Size
ll q;              //Query size
ll k;

//Function to build the sparse table in O(nlogn)
void build() {
    //Initialize the sparce table
    for (int i = 0; i < n; i++) {
        sparce[i][0] = arr[i];
    }
    //Build the sparce table
    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j <= k; j++) {
            ll e1 = sparce[i][j - 1];
            ll e2 = sparce[i + (1LL << (j - 1))][j - 1];
            sparce[i][j] = min(e1, e2);
        }
    }
}
//1 2 3 4 5 6 7 8 9
ll query(ll l, ll r) {
    
}
int main() {
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    k = floor(log2(n)) + 1;
    build();
}
