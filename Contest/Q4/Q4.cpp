#include <bits/stdc++.h>

#include <unordered_map>

#pragma GCC optimize("O2")

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define MOD 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
typedef vector<int> vi;

void input(vector<int>& arr, int n) {
    arr.resize(n);
    loop(i, n) {
        cin >> arr[i];
    }
}
void input2(vector<vector<int> >& arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}
void print(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print2(vector<vector<int> >& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int find(int a, int b, vector<vector<pi> >& graph) {
    vector<int> dis(graph.size() + 2, INT_MAX);
    dis[a] = 0;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    vector<bool> visited(graph.size() + 2, false);
    pq.push(make_pair(0, a));
    while (pq.size()) {
        auto top = pq.top();
        int d = top.first;
        int node = top.second;
        pq.pop();
        if (visited[top.second]) continue;
        visited[top.second] = true;
        for (auto& child : graph[node]) {
            int nd = d + child.second;
            if (nd > dis[child.first]) continue;
            dis[child.first] = nd;
            pq.push(make_pair(nd, child.first));
        }
    }
    // print(dis);
    if (dis[b] == INT_MAX) {
        return -1;
    }
    return dis[b];
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pi> > graph(n);
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        if (a >= n || b >= n) cerr << "Wrong\n";
        graph[a].pb(make_pair(b, w));
        graph[b].pb(make_pair(a, w));
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << find(a, b, graph) << "\n";
    }
}
int main() {
    IOS;
    testcase {
        solve();
    }
    return 0;
}