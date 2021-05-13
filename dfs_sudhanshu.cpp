#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> tree[N];

void dfs(int curr,int parent,int key)
{
    if (curr == key)
    {
        cout<<"Found";
        return;
    }
    for(auto &a:tree[curr])
    {
        if (a == parent)
        {
            continue;
        }
        dfs(a,curr,key);
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int key;
    cin>>key;
    dfs(1,0,key);
}

