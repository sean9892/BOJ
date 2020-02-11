#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define fi first
#define se second
vector<int> adj[300010];
int vis[300010];
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	priority_queue<pii> q;
	q.push(pii(-0,s));
	vis[s]=1;
	while(!q.empty()){
		int d=-q.top().fi;
		int u=q.top().se;
		q.pop();
		if(u==e){
			cout<<d;
			return 0;
		}
		for(int v:adj[u])if(!vis[v]){
			vis[v]=1;
			q.push(pii(-d-1,v));
		}
		if(u>1&&!vis[u-1]){
			vis[u-1]=1;
			q.push(pii(-d-1,u-1));
		}
		if(u<n&&!vis[u+1]){
			vis[u+1]=1;
			q.push(pii(-d-1,u+1));
		}
	}
}
