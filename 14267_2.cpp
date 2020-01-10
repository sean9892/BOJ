#include<bits/stdc++.h>
using namespace std;

const int nmax=100010;
int n;
vector<int> adj[nmax];
int seg[nmax<<2];
int in[nmax],out[nmax];
int lazy[nmax<<2];

int cnt=0;
void dfs(int u){
	in[u]=++cnt;
	for(int v:adj[u])if(!in[v])dfs(v);
	out[u]=cnt;
}

void prop(int idx,int l,int r){
	if(lazy[idx]==0)return;
	seg[idx]+=lazy[idx]*(r-l+1);
	if(l!=r){
		int le=idx<<1,ri=le+1;
		lazy[le]+=lazy[idx];
		lazy[ri]+=lazy[idx];
	}
	lazy[idx]=0;
}

void upd(int idx,int l,int r,int s,int e,int v){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy[idx]=v;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	upd(le,l,m,s,e,v);upd(ri,m+1,r,s,e,v);
	seg[idx]=seg[le]+seg[ri];
	return;
}

int query(int idx,int l,int r,int p){
	prop(idx,l,r);
	if(l>p||r<p)return 0;
	if(l!=r){
		int m=l+r>>1;
		int le=idx<<1,ri=le+1;
		return query(le,l,m,p)+query(ri,m+1,r,p);
	}
	return seg[idx];
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t!=-1)adj[t].push_back(i);
	}
	dfs(1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		upd(1,1,n,in[a],out[a],b);
	}
	for(int i=1;i<=n;i++){
		cout<<query(1,1,n,in[i])<<" ";
	}
}
