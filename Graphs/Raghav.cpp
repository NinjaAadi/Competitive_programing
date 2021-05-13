#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N = 1000;
vector<int> tree[N];

void dfs(int curr, int parent, int search){
    for(int i = 0; i < tree[curr].size(); i++){
        if(tree[curr][i] == parent) continue;
        if(tree[curr][i] == search) {
          cout<<"Found";
          return;
        }
        dfs(tree[curr][i], curr, search);  
    }
}

int main(){
    int nodes;
    cin>>nodes;
    for(int i = 1; i <= nodes - 1; i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int search;;
    cin>>search;
    dfs(1, 0, search);
}

