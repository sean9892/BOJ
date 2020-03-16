#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int sps[22][100010];
int losps[22][100010];
int hisps[22][100010];
int d[100010];
vector<pii> adj[100010];

void dfs(int u,int p){
	for(auto [v,w]:adj[u])if(v!=p){
		losps[0][v]=w;
		hisps[0][v]=w;
		sps[0][v]=u;
		d[v]=d[u]+1;
		dfs(v,u);
	}
}

pii f(int u,int v){
	if(d[u]>d[v])swap(u,v);
	int lo=987654321,hi=-987654321;
	for(int i=21;i>=0;i--)if(d[v]-d[u]>=(1<<i)){
		lo=min(lo,losps[i][v]);
		hi=max(hi,hisps[i][v]);
		v=sps[i][v];
	}
	if(x==y)return pii(lo,hi);
	for(int i=21;i>=0;i--)if(sps[i][u]!=sps[i][v]){
		lo=min({lo,losps[i][u],losps[i][v]});
		hi=max({hi,hisps[i][u],hisps[i][v]});
		u=sps[i][u];v=sps[i][v];
	}
	lo=min({lo,losps[0][u],losps[0][v]});
	hi=max({hi,hisps[0][u],hisps[0][v]});
	return pii(lo,hi);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	losps[0][1]=987654321;
	hisps[0][1]=-987654321;
	sps[0][1]=1;
	dfs(1,1);
	for(int i=1;i<22;i++){
		for(int j=1;j<=n;j++){
			losps[i][j]=min(losps[i-1][j],losps[i-1][sps[i-1][j]]);
			hisps[i][j]=max(hisps[i-1][j],hisps[i-1][sps[i-1][j]]);
			sps[i][j]=sps[i-1][sps[i-1][j]];
		}
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		int a,b;
		tie(a,b)=f(x,y);
		cout<<a<<" "<<b<<"\n";
	}
}

