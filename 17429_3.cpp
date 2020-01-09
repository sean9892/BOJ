#include<bits/stdc++.h>
using namespace std;
using uint=unsigned int;

const int nmax=500010;

int n,q;
vector<int> adj[nmax];
int w[nmax],p[nmax],d[nmax];
int in[nmax],out[nmax];
int hld[nmax];
uint seg[nmax<<2];
uint lazy1[nmax<<2],lazy2[nmax<<2];

void dfs(int u){
	w[u]=1;
	for(int v:adj[u])if(!w[v]){
		p[v]=u;d[v]=d[u]+1;
		dfs(v);
		w[u]+=w[v];
	}
}

int ord;
void dfs2(int u){
	int cc=-1;
	in[u]=++ord;
	for(int v:adj[u])if(p[v]==u&&(cc==-1||w[v]>w[cc]))cc=v;
	if(cc!=-1){
		hld[cc]=hld[u];dfs2(cc);
	}
	for(int v:adj[u])if(p[v]==u&&v!=cc){
		hld[v]=v;dfs2(v);
	}
	out[u]=ord;
}

void prop(int idx,int l,int r){
	if(lazy1[idx]==1&&lazy2[idx]==0)return;
	seg[idx]*=lazy1[idx];
	seg[idx]+=lazy2[idx]*(r-l+1);
	if(l^r){
		int le=idx<<1,ri=le+1;
		lazy1[le]*=lazy1[idx];lazy2[le]*=lazy1[idx];lazy2[le]+=lazy2[idx];
		lazy1[ri]*=lazy1[idx];lazy2[ri]*=lazy1[idx];lazy2[ri]+=lazy2[idx];
	}
	lazy1[idx]=1;lazy2[idx]=0;
}

void su(int idx,int l,int r,int s,int e,uint a,uint b){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=a;lazy2[idx]=b;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le+1;
	su(le,l,m,s,e,a,b);su(ri,m+1,r,s,e,a,b);
	seg[idx]=seg[le]+seg[ri];
}

uint sq(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le+1;
	return sq(le,l,m,s,e)+sq(ri,m+1,r,s,e);
}

void updSub(int x,uint a,uint b){
	su(1,1,n,in[x],out[x],a,b);
}

void updPth(int x,int y,uint a,uint b){
	while(hld[x]!=hld[y]){
		if(d[hld[x]]>d[hld[y]])swap(x,y);
		su(1,1,n,in[hld[y]],in[y],a,b);
		y=p[hld[y]];
	}
	if(d[x]>d[y])swap(x,y);
	su(1,1,n,in[x],in[y],a,b);
}

uint quSub(int x){
	return sq(1,1,n,in[x],out[x]);
}

uint quPth(int x,int y){
	uint res=0;
	while(hld[x]!=hld[y]){
		if(d[hld[x]]>d[hld[y]])swap(x,y);
		res+=sq(1,1,n,in[hld[y]],in[y]);
		y=p[hld[y]];
	}
	if(d[x]>d[y])swap(x,y);
	res+=sq(1,1,n,in[x],in[y]);
	return res;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	for(int i=0;i<(nmax<<2);i++)lazy1[i]=1,lazy2[i]=0;
	hld[1]=1;
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);dfs2(1);
	for(int i=0;i<q;i++){
		int t,x,y;
		uint v;
		cin>>t;
		if(t==1){
			cin>>x>>v;
			updSub(x,1,v);
		}
		if(t==2){
			cin>>x>>y>>v;
			updPth(x,y,1,v);
		}
		if(t==3){
			cin>>x>>v;
			updSub(x,v,0);
		}
		if(t==4){
			cin>>x>>y>>v;
			updPth(x,y,v,0);
		}
		if(t==5){
			cin>>x;
			cout<<quSub(x)<<"\n";
		}
		if(t==6){
			cin>>x>>y;
			cout<<quPth(x,y)<<"\n";
		}
	}
}
