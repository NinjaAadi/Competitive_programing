#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> in, lo;
    vector<vector<int>> res;
    int timer;
    void dfs(int curr, int par) {
        if (visited[curr]) return;
        in[curr] = lo[curr] = timer++;
        for (auto& child : graph[curr]) {
            if (child == par)
                continue;
            else if (visited[child]) {
                lo[curr] = min(lo[curr], lo[child]);
            } else {
                dfs(child, par);
                lo[curr] = min(lo[child], lo[curr]);
                if (lo[child] > in[curr]) {
                    res.push_back({curr, child});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edge) {
        graph.resize(n);
        for (auto& i : edge) {
            int u = i[0];
            int v = i[1];
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; i++) {
            timer = 0;
            dfs(i, -1);
        }
        return res;
    }
};