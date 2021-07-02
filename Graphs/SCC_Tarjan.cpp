class Solution {
   public:
    vector<int> in;
    vector<int> lo;
    stack<int> s;
    vector<bool> instack;
    vector<bool> visited;
    int timer = 0;
    vector<vector<int>> res;
    void dfs(int curr, vector<int> graph[]) {
        visited[curr] = true;
        in[curr] = lo[curr] = timer++;
        instack[curr] = true;
        s.push(curr);
        for (auto &child : graph[curr]) {
            if (visited[child] == false) {
                dfs(child, graph);
                if (instack[child])
                    lo[curr] = min(lo[curr], lo[child]);
            } else {
                if (instack[child]) {
                    lo[curr] = min(lo[curr], in[child]);
                }
            }
        }
        if (in[curr] == lo[curr]) {
            vector<int> temp;
            while (s.size() && s.top() != curr) {
                temp.push_back(s.top());
                instack[s.top()] = false;
                s.pop();
            }
            s.pop();
            instack[curr] = false;
            temp.push_back(curr);
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[]) {
        in.resize(n + 1, 0);
        lo.resize(n + 1, 0);
        instack.resize(n + 1, false);
        visited.resize(n + 1, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};