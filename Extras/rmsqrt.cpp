#include <bits/stdc++.h>
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
using namespace std;

//Program to implement square root decomposition for range sum queries and updation

//Function to precompute sum of each blocks

long long mini[200006];
long long block_num[200006];
void presum(long long arr[], long long n, long long size) {
    memset(mini, 0, sizeof(mini));
    memset(block_num, 0, sizeof(block_num));
    long long bi = 0;
    long long bmin = INT_MAX;
    long long counter = 0;
    for (long long i = 0; i < n; i++) {
        counter++;
        bmin = min(arr[i], bmin);
        block_num[i] = bi;
        if (counter == size) {
            counter = 0;
            mini[bi] = bmin;
            bmin = INT_MAX;
            bi++;
        }
    }
}
long long getans(long long l, long long r, long long arr[], long long n) {
    long long b1 = block_num[l];
    long long b2 = block_num[r];
    long long res = INT_MAX;
    if (b1 == b2) {
        for (long long i = l; i <= r; i++) {
            res = min(res, arr[i]);
        }
        return res;
    }
    long long min_start = INT_MAX;
    long long min_mid = INT_MAX;
    long long min_end = INT_MAX;
    long long counter = l;
    while (block_num[counter] == b1) {
        min_start = min(arr[counter], min_start);
        counter++;
    }
    for (long long i = b1 + 1; i < b2; i++) {
        min_mid = min(mini[i], min_mid);
        counter += sqrt(n);
    }
    while (counter <= r) {
        min_end = min(arr[counter], min_end);
        counter++;
    }
    return min(min(min_start, min_mid), min_end);
}
int main() {
    long long n;
    long long q;
    cin >> n >> q;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //Now we will make sqrt(n) blocks of size sqrt(n)
    long long size = sqrt(n);
    presum(arr, n, size);
    while (q--) {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << getans(l, r, arr, n) << "\n";
    }
}
