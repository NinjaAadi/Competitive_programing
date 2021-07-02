#include <bits/stdc++.h>

using namespace std;

//ans vectors
vector<int> art;
vector<vector<int>> bridges;

//graph utils
vector<vector<int>> graph;
vector<bool> visited;
int timer = 0;
int n, m;
//for low and in time
vector<int> lo;
vector<int> in;

void dfsutil(int curr, vector<bool> &taken) {
    if (taken[curr]) return;
    taken[curr] = true;
    for (auto &child : graph[curr]) dfsutil(child, taken);
}

//function to check if root vertex is a articulation point or not
bool check(int curr) {
    int count = 0;
    vector<bool> taken(n, false);
    taken[curr] = true;
    for (auto &child : graph[curr]) {
        if (count == 0) {
            dfsutil(child, taken);
            count++;
            continue;
        }

        if (taken[child] == true) {
            continue;
        } else {
            return true;
        }
        count++;
    }
    return false;
}

void dfs(int curr, int par) {
    in[curr] = lo[curr] = timer++;
    visited[curr] = true;
    for (auto &child : graph[curr]) {
        if (child == par) continue;
        if (!visited[child]) {
            dfs(child, curr);
            lo[curr] = min(lo[curr], lo[child]);
            // cout << curr << " " << child << endl;
            // cout << in[curr] << " " << lo[child] << endl;
            //For bridge
            if (lo[child] > in[curr]) {
                bridges.push_back({curr, child});
            }
            //For articulation
            if (lo[child] >= in[curr] && par != -1) {
                art.push_back(curr);
            }
        } else {
            lo[curr] = min(lo[curr], in[child]);
        }
    }
    //if it is root
    if (par == -1) {
        if (check(curr)) {
            art.push_back(curr);
        }
    }
}
int main() {
    cin >> n >> m;

    int u, v;
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    in.resize(n + 1, false);
    lo.resize(n + 1, false);

    //input
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    sort(art.begin(), art.end());
    for (auto &i : bridges) sort(i.begin(), i.end());
    sort(bridges.begin(), bridges.end());
    cout << art.size() << endl;
    for (auto &i : art) cout << i << " ";
    cout << endl;
    cout << bridges.size() << endl;
    for (auto &i : bridges) {
        cout << i[0] << " " << i[1] << endl;
    }
}