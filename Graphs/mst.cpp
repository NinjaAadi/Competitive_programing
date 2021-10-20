#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> parent;
    int findpar(int a) {
        if (parent[a] == a) return a;
        return parent[a] = findpar(parent[a]);
    }
    bool merge(int a, int b) {
        int pa = findpar(a);
        int pb = findpar(b);
        if (pa == pb) return false;
        parent[a] = pb;
        return true;
    }
    struct Comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        }
    };
    typedef vector<int> vi;
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        parent.resize(n);
        priority_queue<vi, vector<vi>, Comp> pq;
        for(int i = 0;i<n;i++){
            pq.push(adj[i])
        }
    }
    int ans = 0;
    while (pq.size()) {
        auto top = pq.top() : pq.pop();
        if (merge(top[0], top[1])) {
            ans +=
        }
    }
};