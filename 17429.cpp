#include<bits/stdc++.h>
using namespace std;
using uint=unsigned int;

const int nmax=500010;

int n;
vector<int> adj[nmax];
int sz[nmax];
int hld[nmax];
int ord[nmax];
int dep[nmax];
int p[nmax];
uint seg[nmax<<2];
uint lazy1[nmax<<2];
uint lazy2[nmax<<2];

void dfs(int now){
	sz[now]=1;
	for(int nxt:adj[now])if(!sz[now]){
		p[nxt]=now;
		dep[nxt]=dep[now]+1;
		dfs(nxt);
		sz[now]+=sz[nxt];
	}
}

int cnt=0;
void dfs2(int now){
	int cc=-1;
	ord[now]=++cnt;
	for(int nxt:adj[now])if(p[nxt]==now&&(cc==-1||sz[nxt]>sz[cc]))cc=nxt;
	if(cc!=-1){
		hld[cc]=hld[now];dfs2(cc);
	}
	for(int nxt:adj[now])if(p[nxt]==now&&nxt!=cc){
		hld[nxt]=nxt;dfs2(nxt);
	}
}

void prop(int idx,int l,int r){
	if(lazy1[idx]==1&&lazy2[idx]==0)return;
	seg[idx]=seg[idx]*lazy1[idx]+lazy2[idx]*(r-l+1);
	if(l!=r){
		int le=idx<<1,ri=le+1;
		lazy1[le]*=lazy1[idx];lazy2[le]*=lazy1[idx];
		lazy1[ri]*=lazy1[idx];lazy2[ri]*=lazy1[idx];
		lazy2[le]+=lazy2[idx];
		lazy2[ri]+=lazy2[idx];
	}
	lazy1[idx]=1;lazy2[idx]=0;
}

void updpl(int idx,int l,int r,int s,int e,uint v){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=1;lazy2[idx]=v;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	updpl(le,l,m,s,e,v);updpl(ri,m+1,r,s,e,v);
	seg[idx]=seg[le]+seg[ri];
}

void updml(int idx,int l,int r,int s,int e,uint x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=x;lazy2[idx]=0;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	updml(le,l,m,s,e,x);updml(ri,m+1,r,s,e,x);
	seg[idx]=seg[le]+seg[ri];
}

uint squ(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	return squ(le,l,m,s,e)+squ(ri,m+1,r,s,e);
}

void updpathpl(int a,int b,uint v){//3
	while(hld[a]!=hld[b]){
		if(dep[a]>dep[b])swap(a,b);
		updpl(1,1,n,ord[hld[b]],ord[b],v);
		b=p[hld[b]];
	}
	if(dep[a]>dep[b])swap(a,b);
	updpl(1,1,n,ord[a],ord[b],v);
}

void updpathml(int a,int b,uint x){//4
	while(hld[a]!=hld[b]){
		if(dep[a]>dep[b])swap(a,b);
		updml(1,1,n,ord[hld[b]],ord[b],x);
		b=p[hld[b]];
	}
	if(dep[a]>dep[b])swap(a,b);
	updml(1,1,n,ord[a],ord[b],x);
}

uint qupath(int a,int b){//6
	uint sum=0;
	while(hld[a]!=hld[b]){
		if(dep[a]>dep[b])swap(a,b);
		sum+=squ(1,1,n,a,b);
		b=p[hld[b]];
	}
	if(dep[a]>dep[b])swap(a,b);
	sum+=squ(1,1,n,ord[a],ord[b]);
	return sum;
}

void print(){
	for(int i=1;i<=n;i++){
		cout<<squ(1,1,n,i,i)<<" ";
	}
	cout<<" <<\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int q;
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);dfs2(1);
	fill(lazy1,lazy1+(nmax<<2),1);
	for(int i=0;i<q;i++){
		int a;
		cin>>a;
		cout<<a<<"|\n";
		if(a==1){
			int x;
			uint v;
			cin>>x>>v;
			updpl(1,1,n,ord[x],ord[x]+sz[x]-1,v);
		}
		if(a==2){
			int x,y;
			uint v;
			cin>>x>>y>>v;
			updpathpl(x,y,v);
		}
		if(a==3){
			int x;
			uint v;
			cin>>x>>v;
			updml(1,1,n,ord[x],ord[x]+sz[x]-1,v);
		}
		if(a==4){
			int x,y;
			uint v;
			cin>>x>>y>>v;
			updpathml(x,y,v);
		}
		if(a==5){
			int x;
			cin>>x;
			cout<<squ(1,1,n,ord[x],ord[x]+sz[x]-1)<<"\n";
		}
		if(a==6){
			int x,y;
			cin>>x>>y;
			cout<<qupath(x,y)<<"\n";
		}
		print();
	}
}
