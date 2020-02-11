#include<bits/stdc++.h>
using namespace std;

const int nmax=1010;

int n,r;
vector<int> adj[nmax];
int c[nmax];
int w[nmax];
int s[nmax];
int dp[nmax];

void dfs1(int u){
	w[u]=1;
	s[u]=c[u];
	for(int v:adj[u]){
		dfs1(v);
		w[u]+=w[v];
		s[u]+=s[v];
	}
}

void dsf2(int u){
	
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>r;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	dfs1(r);dfs2(r);
}
