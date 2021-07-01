#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> graph;
    vector<bool> visited;
    stack<int> s;
    void reverse(vector<int> adj[], int n) {
        graph.resize(n + 1);
        for (int i = 0; i < n; i++) {
            for (auto &child : adj[i]) {
                graph[child].push_back(i);
            }
        }
    }
    void dfs(int curr, vector<int> adj[]) {
        if (visited[curr]) return;
        visited[curr] = true;
        for (auto &child : adj[curr]) {
            dfs(child, adj);
        }
        s.push(curr);
    }
    void dfsrev(int curr) {
        if (visited[curr]) return;
        visited[curr] = true;
        for (auto &child : graph[curr]) {
            dfsrev(child);
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        reverse(adj, V);
        visited.resize(V + 1, false);
        for (int i = 0; i < V; i++) dfs(i, adj);
        visited.assign(V + 1, false);
        int ans = 0;
        while (!s.empty()) {
            if (visited[s.top()]) {
                s.pop();
                continue;
            }
            dfsrev(s.top());
            s.pop();
            ans++;
        }
        return ans;
    }
};