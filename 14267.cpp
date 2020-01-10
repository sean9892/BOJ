#include<bits/stdc++.h>
using namespace std;

const int nmax=100010;
int n;
int in[nmax],out[nmax];
vector<int> adj[nmax];

int cnt=0;
void dfs(int u){
	in[u]=++cnt;
	for(int v:adj[u]){
		dfs(v);
	}
	out[u]=cnt;
}

int seg[nmax<<2];
void upd(int idx,int l,int r,int s,int e,int v){
	if(l>e||r<s)return;
	if(l^r){
		int m=l+r>>1,le=idx<<1,ri=le+1;
		upd(le,l,m,s,e,v);upd(ri,m+1,r,s,e,v);
		seg[idx]=seg[le]+seg[ri];
		return;
	}
	seg[idx]+=v;
}

int query(int idx,int l,int r,int p){
	if(l>p||r<p)return 0;
	if(l^r){
		int m=l+r>>1,le=idx<<1,ri=le+1;
		return query(le,l,m,p)+query(ri,m+1,r,p);
	}
	return seg[idx];
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		adj[x].push_back(i);
	}
	dfs(1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		upd(1,1,n,in[a],out[a],b);
	}
	for(int i=1;i<=n;i++){
		cout<<query(1,1,n,i)<<" ";
	}
}
