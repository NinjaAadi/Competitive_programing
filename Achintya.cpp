#include<bits.stdc++.h>
using namespace std;


const int N=10e3;
vector<int>tree[N];


void dfs(int curr,int parent,int key){
	if(curr==key){
		cout<<"element found"<<curr<<endl;
		return;
	}
	for(auto &child:tree[curr]){
		if(child==parent)
			continue;
		dfs(child,curr,key);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<n-1;i++){
		int x,y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	int key;
	cin>>key;
	dfs(0,0,key);
}
