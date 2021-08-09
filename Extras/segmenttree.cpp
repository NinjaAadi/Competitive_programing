#include <bits/stdc++.h>

using namespace std;

vector<int> segtree;
vector<int> arr;

//build the segment tree
int build(int tl, int tr, int segid) {
    //base case
    if (tl == tr) {
        segtree[segid] = arr[tl];
        return arr[tl];
    }
    int m = (tl + tr) / 2;
    int left = build(tl, m, 2 * segid + 1);
    int right = build(m + 1, tr, 2 * segid + 2);

    return segtree[segid] = min(left, right);
}

int pointupdateutil(int tl, int tr, int segid, int ele, int id) {
    if (id < tl || id > tr) return segtree[segid];
    if (tl == tr) {
        segtree[segid] = ele;
        return ele;
    }
    int m = (tl + tr) / 2;
    int left = INT_MAX;
    int right = INT_MAX;

    left = pointupdateutil(tl, m, 2 * segid + 1, ele, id);
    right = pointupdateutil(m + 1, tr, 2 * segid + 2, ele, id);
    int curr = min(left, right);
    curr = min(curr, segtree[segid]);
    return segtree[segid] = curr;
}
int queryutil(int tl, int tr, int ql, int qr, int segid) {
    //base case
    // 1 -> Completely overlap
    if (tl >= ql && tr <= qr) {
        return segtree[segid];
    }
    //Completely outside the range
    if (tr < ql || tl > qr) {
        return segtree[segid];
    }

    //Partial overlap
    int mid = (tl + tr) / 2;
    return min(queryutil(tl, mid, ql, qr, 2 * segid + 1), queryutil(mid + 1, tr, ql, qr, 2 * segid + 2));
}
void rangeupdateutil(int tl, int tr, int ul, int ur, int segid, int diff) {
    if (tl == tr) {
        segtree[segid] += diff;
        return;
    }
    if (ur < tl || ul > tr) {
        return;
    }
    int mid = (tl + tr) / 2;
    rangeupdateutil(tl, mid, ul, ur, 2 * segid + 1, diff);
    rangeupdateutil(mid + 1, tr, ul, ur, 2 * segid + 2, diff);

    segtree[segid] = min(segtree[2 * segid + 1], segtree[2 * segid + 2]);
}
int n;
int query(int l, int r) {
    return queryutil(0, n - 1, l, r, 0);
}
void pointupdate(int i, int newele) {
    int dummy = pointupdateutil(0, n - 1, 0, newele, i);
}
void rangeupdate(int l, int r, int diff) {
    rangeupdateutil(0, n - 1, l, r, 0, diff);
}
int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //resize seg tree
    segtree.resize(4 * n + 1);
    build(0, n - 1, 0);
    // cout << query(1, 3) << endl;
    // pointupdate(1, 5);
    // cout << query(1, 3) << endl;
    // pointupdate(3, 10);
    // cout << query(1, 3) << endl;
    rangeupdate(1, 3, 10);
    cout << query(1, 3) << endl;
    rangeupdate(7, 9, 10);
    cout << query(7, 9) << endl;
}