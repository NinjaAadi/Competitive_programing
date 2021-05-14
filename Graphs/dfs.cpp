#include <bits/stdc++.h>

using namespace std;

//dfs on trees
const int N = 1e5;

vector<int> tree[N];  //Vector to store the tree

void dfs(int curr, int par) {
    for (int &child : tree[curr]) {
        if (child == par) continue;
        dfs(child, curr);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
}