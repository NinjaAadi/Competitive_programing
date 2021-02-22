#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2e5 + 3;
ll si;           //Variable to store the square root of n
ll n, q;         //Number of elements and number of queries
ll arr[N];       //Array to store the elements
ll blocknum[N];  //Array to store the block number of each elements
ll block_min[605];

//Initializer function
void init() {
    for (ll i = 0; i < 605; i++) {
        block_min[i] = LLONG_MAX;
    }
}

//Function to build the square root array
void squareroot() {
    ll counter = 0;  //Variable to increment the block number
    ll bmin = LLONG_MAX;
    ll count = 0;
    for (ll i = 0; i < n; i++) {
        count++;
        blocknum[i] = counter;
        bmin = min(bmin, arr[i]);
        if (count == si) {
            block_min[counter] = bmin;  //Set the minimum of this block
            counter++;                  //Increment the block number
            bmin = LLONG_MAX;           //Initialize the minimume element of each block
            count = 0;
        }
    }
}

ll query(ll l, ll r) {
    ll b1 = blocknum[l];  //Block number of left index
    ll b2 = blocknum[r];  //Block number of right index

    //If they are of the same block
    ll res = LLONG_MAX;
    if (b1 == b2) {
        for (ll i = l; i <= r; i++) {
            res = min(res, arr[i]);
        }
        return res;
    }
    ll b = b1;
    ll index = l;
    ll min1 = LLONG_MAX;
    ll min2 = LLONG_MAX;
    ll min3 = LLONG_MAX;

    //Atmost root(N);
    while (blocknum[index] == b1) {
        min1 = min(min1, arr[index]);
        index++;
    }
    //Atmost root(N);
    for (ll i = b1 + 1; i <= b2 - 1; i++) {
        min2 = min(min2, block_min[i]);
        index += si;
    }
    //Atmost root(N);
    while (index <= r) {
        min3 = min(min3, arr[index]);
        index++;
    }
    return min(min(min1, min2), min3);
}

//Program for square root decomposition
int main() {
    init();
    cin >> n >> q;
    si = sqrt(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //Decompose the array into square roots
    squareroot();
    ll l, r;
    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        cout << query(l, r) << "\n";
    }
}
