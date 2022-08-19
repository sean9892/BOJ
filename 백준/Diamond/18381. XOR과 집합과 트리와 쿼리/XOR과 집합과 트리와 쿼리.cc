#include<bits/stdc++.h>
using namespace std;

const int nmax=100010;

int bitlen(int x){
	int c=0;
	while(x){
		x/=2;
		c++;
	}
	return c;
}

int f(int a,int b){
	if(a!=0){
		while(a%2==0){
			a/=2;
		}
	}
	if(b!=0){
		while(b%2==0){
			b/=2;
		}
	}
	if(a<b)swap(a,b);
	if(b==0)return a;
	int A=bitlen(a),B=bitlen(b);
	int c=(b<<(A-B));
	return f(a^c,b);
}

int w[nmax],p[nmax],d[nmax];
int ord[nmax],rev[nmax],hld[nmax];
vector<int> g[nmax];

void dfs(int u){
	w[u]=1;
	for(int v:g[u]){
		if(!w[v]){
			p[v]=u;
			d[v]=d[u]+1;
			dfs(v);
			w[u]+=w[v];
		}
	}
}

int cnt=0;
void dfs2(int u){
	int cc=-1;
	ord[u]=++cnt;
	rev[cnt]=u;
	for(int v:g[u]){
		if(p[v]==u&&(cc==-1||w[v]>w[cc]))cc=v;
	}
	if(cc!=-1){
		hld[cc]=hld[u];
		dfs2(cc);
	}
	for(int v:g[u]){
		if(p[v]==u&&v!=cc){
			hld[v]=v;
			dfs2(v);
		}
	}
}

int seg[nmax<<2];
int arr[nmax];
int brr[nmax];
int N,Q;

void init(int idx,int l,int r){
	if(l==r){
		seg[idx]=brr[l];
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);
	init(ri,m+1,r);
	seg[idx]=f(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return f(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

void qu(int a,int b){
	int res=0;
	while(hld[a]!=hld[b]){
		if(d[hld[a]]>d[hld[b]])swap(a,b);
		int top=hld[b];
		res=f(res,query(1,1,N,ord[top],ord[b]));
		b=p[top];
	}
	if(d[a]>d[b])swap(a,b);
	res=f(res,query(1,1,N,ord[a],ord[b]));
	cout<<res<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		cin>>arr[i];
	}
	for(int i=1;i<N;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);dfs2(1);
	for(int i=1;i<=N;i++){
		brr[i]=arr[rev[i]];
	}
	init(1,1,N);
	for(int i=1;i<=Q;i++){
		int a,b;
		cin>>a>>b;
		qu(a,b);
	}
}