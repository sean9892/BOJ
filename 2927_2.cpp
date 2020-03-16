#include<bits/stdc++.h>
using namespace std;

const int BRID = 1;
const int PENG = 2;
const int EXCU = 3;

struct Query{
	int type;
	int a,b;
};

vector<Query> qv;

struct UF{
	int p[30010];
	UF(){
		memset(p,-1,sizeof(p));
	}
	int fnd(int u){
		if(p[u]<0)return u;
		return p[u]=fnd(p[u]);
	}
	int mer(int u,int v){
		u=fnd(u);v=fnd(v);
		if(u==v)return 0;
		p[v]+=p[u];
		p[u]=v;
		return 1;
	}
};

int n;
int ini[30010];
vector<int> g[30010];
int sz[30010],d[30010],p[30010],hld[30010],in[30010];

void dfs1(int v){
	sz[v]=1;
	for(int& i:g[v])if(!sz[i]){
		d[i]=d[v]+1;p[i]=v;
		dfs1(i);sz[v]+=sz[i];
		if(sz[i]>sz[g[v][0]])swap(i,g[v][0]);
	}
}

int pv;
void dfs2(int v){
	in[v]=++pv;
	for(auto i:g[v])if(i!=p[v]){
		hld[i]=i==g[v][0]?hld[v]:i;
		dfs2(i);
	}
}

int seg[30010<<2];

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l==r){
		seg[idx]=v;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
	seg[idx]=seg[le]+seg[ri];
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int qu(int a,int b){
	int r=0;
	while(hld[a]!=hld[b]){
		if(d[hld[a]]>d[hld[b]])swap(a,b);
		int top=hld[b];
		r+=query(1,1,n,in[top],in[b]);
		b=p[top];
	}
	if(d[a]>d[b])swap(a,b);
	r+=query(1,1,n,in[a],in[b]);
	return r;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ini[i];
	int m;
	cin>>m;
	{
		UF uf;
		for(int i=0;i<m;i++){
			string t;
			int a,b;
			cin>>t>>a>>b;
			if(t[0]=='b'){
				qv.push_back({BRID,a,b});
				if(uf.mer(a,b)){
					g[a].push_back(b);
					g[b].push_back(a);
				}
			}
			if(t[0]=='p'){
				qv.push_back({PENG,a,b});
			}
			if(t[0]=='e'){
				qv.push_back({EXCU,a,b});
			}
		}
	}
	p[1]=-1;
	for(int i=1;i<=n;i++)if(!sz[i]){
		hld[i]=i;
		dfs1(i);dfs2(i);
	}
	for(int i=1;i<=n;i++)upd(1,1,n,in[i],ini[i]);
	UF uf;
	for(int i=0;i<m;i++){
		int t=qv[i].type,a=qv[i].a,b=qv[i].b;
		if(t==BRID){
			if(d[a]>d[b])swap(a,b);
			cout<<(uf.mer(a,b)?"yes\n":"no\n");
		}
		if(t==PENG){
			upd(1,1,n,in[a],b);
		}
		if(t==EXCU){
			if(uf.fnd(a)==uf.fnd(b)){
				cout<<qu(a,b)<<"\n";
			}
			else{
				cout<<"impossible\n";
			}
		}
	}
}
