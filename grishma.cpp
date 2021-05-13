#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int>tree[N];

void Print(int node){
  cout<<"currently in "<<node<<endl;
}
void dfs(int curr,int par){
	if(curr==ele)
		cout<<"element "<<ele<<" found"<<endl;
		return;
  Print(curr);
  for(int &child:tree[curr]){
    if(child==par)continue;
    dfs(child,curr);
    Print(curr);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
	int ele;
	cin>>ele;
  dfs(1,0,ele);
}
