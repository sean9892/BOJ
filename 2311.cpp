#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

#define mems(x,v) memset(x,v,sizeof(x))

const int nmax=1010;
int n,m;
int c[nmax][nmax],f[nmax][nmax];
vector<pii> adj[nmax];
int par[nmax];
int dist[nmax];

int r(int u,int v){
	return c[u][v]-f[u][v];
}

void addEdge(int u,int v,int k){
	adj[u].emplace_back(v,k);
	adj[v].emplace_back(u,k);
	c[u][v]=c[v][u]=1;
}

int mcmf(int src,int snk){
	int res=0;
	for(int i=0;i<2;i++){
		mems(par,-1);
		mems(dist,0x3f);
		priority_queue<pii> q;
		par[src]=src;
		dist[src]=0;
		q.emplace(-0,src);
		while(!q.empty()&&par[snk]==-1){
			int u,d;
			tie(d,u)=q.top();q.pop();
			d=-d;
			if(dist[u]<d)continue;
			dist[u]=d;
			for(auto i:adj[u]){
				int v,w;
				tie(v,w)=i;
				if(r(u,v)>0&&dist[v]>d+w){
					dist[v]=d+w;
					par[v]=u;
					q.emplace(-dist[v],v);
				}
			}
		}
		for(int p=snk;p!=src;p=par[p]){
			f[par[p]][p]++;
			f[p][par[p]]--;
		}
		res+=dist[snk];
	}
	return res;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		addEdge(a,b,c);
	}
	int res=mcmf(1,n);
	cout<<res;
}
