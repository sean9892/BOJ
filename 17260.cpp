#include<bits/stdc++.h>
using namespace std;

int n,k;
int h[200010];
vector<int> g[200010];
int dp[200010];

int dfs(int u,int p){
	int res=0;
	for(int v:g[u])if(v!=p){
		int r=dfs(v,u);
		if(r>=h[u])res=max(h[u]+(r-h[u])/2,res);
	}
	return max(res,h[u]);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>h[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i:g[k]){
		int r=dfs(i,k);
		if(r>=h[k]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
}
