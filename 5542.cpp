#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using edge=tuple<int,int,int>;

const int nmax=100010;

int n,m,k,q;
int dist[nmax];
int qv[nmax][2];
vector<pii> adj[nmax];
vector<edge> e;

struct UF{
	int p[nmax];
	UF(){
		memset(p,-1,sizeof(p));
	}
	int fnd(int u){
		return p[u]<0?u:(p[u]=fnd(p[u]));
	}
	int mer(int u,int v){
		u=fnd(u);v=fnd(v);
		if(u==v)return 0;
		p[u]+=p[v];
		p[v]=u;
		return 1;
	}
};

int lo[nmax],hi[nmax];
int r[nmax];

int vis[nmax];
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v,w;
		tie(v,w)=adj[u][i];
		if(!vis[v]){
			e.emplace_back(u,v,min(dist[u],dist[v]));
			dfs(v);
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k>>q;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	for(int i=0;i<k;i++){
		int x;cin>>x;
		adj[0].emplace_back(x,0);
	}
	priority_queue<pii> pq;
	pq.emplace(0,0);
	while(!pq.empty()){
		int d,u;
		tie(d,u)=pq.top();pq.pop();d=-d;
		if(dist[u]<d)continue;
		dist[u]=d;
		for(int i=0;i<adj[u].size();i++){
			int v,w;
			tie(v,w)=adj[u][i];
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.emplace(-dist[v],v);
			}
		}
	}
	fill(hi,hi+nmax,m);
	dfs(1);
	sort(e.begin(),e.end(),greater<edge>());
	for(int i=0;i<q;i++){
		cin>>qv[i][0]>>qv[i][1];
	}
	while(1){
		int flag=0;
		vector<int> x[nmax];
		for(int i=0;i<q;i++)if(lo[i]+1<hi[i]){
			flag=0;
			x[lo[i]+hi[i]>>1].push_back(i);
		}
		if(flag)break;
		
		UF uf;
		for(int i=0;i<m;i++){
			int u,v,w;
			tie(w,u,v)=e[i];
			uf.mer(u,v);
			for(int j:x[i+1]){
				int a=uf.fnd(qv[j][0]),b=uf.fnd(qv[j][1]);
				if(a==b){
					hi[j]=i+1;
					r[j]=w;
				}
				else lo[j]=i+1;
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<r[i]<<"\n";
	}
}
