#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>tree[N];//Vctor to Store Tree
void dfs(int curr,int par,int search){
  cout<<curr<<"\n";
  for(int &child:tree[curr])
  {
    if(child==par)continue;
    if(tree[child]==search)
    {
      cout<<child;
      break;
    }
    dfs(child,curr,search);
  }
  cout<<"NOt Found"
}
int main()
{
  int nodes,edges;
  cin>>nodes;
  for(int i=1;i<=(nodes-1);i++)
  {
    int u,v;
    cin>>u>>v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  int search=0;
  cin>>search;
  dfs(1,0,search);  
}