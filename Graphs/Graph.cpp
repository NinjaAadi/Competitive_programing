//Using adjacency matrix
#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

//int graph[N][N];

vector<pair<int, int> > graph[N];

void init() {
    //Make every node undefined
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         graph[i][j] = INT_MAX;
    //     }
    // }
}

int main() {
    init();
    //Take input of total number of vertices and total edges
    int v, e;
    cin >> v >> e;
    // for (int i = 0; i < e; i++) {
    //     int a, b, w;
    //     cin >> a >> b >> w;
    //     graph[a][b] = w;
    // }
    // for (int i = 1; i <= v; i++) {
    //     cout << "Node " << i << " : ";
    //     for (int j = 1; j <= v; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //Using adjacency list as well
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
    }
    for (int i = 1; i <= v; i++) {
        cout << "Node " << i << " : ";
        for (auto j : graph[i]) {
            cout << "(" << j.first << "," << j.second << "),";
        }
        cout << endl;
    }
}