#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    stack<int> s;
    vector<int> visited;
    int dfs(int curr, vector<int> graph[]) {
        if (visited[curr]) return;
        visited[curr] = true;
        for (auto &child : graph[curr]) {
            dfs(child, graph);
        }
        s.push(curr);
    }
    int visit(int curr, vector<int> graph[]) {
        if (visited[curr]) return;
        visited[curr] = true;
        for (auto &child : graph[curr]) {
            dfs(child, graph);
        }
    }
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[]) {
        vector<int> graph[n];
        for (int i = 0; i < n; i++) {
            for (auto &child : adj[i]) {
                graph[child].push_back(i);
            }
        }
        visited.resize(n, false);
        for (int i = 0; i < n; i++) {
            dfs(i, adj);
        }
        int connected = 0;
        visited.assign(n, false);
        while (s.size()) {
            int top = s.top();
            s.pop();
            if (visited[top]) continue;
            visit(top, graph);
            connected++;
        }
        return connected;
    }
};