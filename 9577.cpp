#include<bits/stdc++.h>
using namespace std;

#define mems(x,v) memset(x,v,sizeof(x))

const int nmax=310;

int n,m;
vector<int> adj[nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int p[nmax];

int r(int u,int v){
	return c[u][v]-f[u][v];
}

int nwf(int src,int snk){
	int flo=0;
	while(1){
		mems(p,-1);
		queue<int> q;
		q.push(src);
		p[src]=src;
		while(!q.empty()&&p[snk]==-1){
			int u=q.front();q.pop();
			for(int v:adj[u]){
				if(r(u,v)>0&&p[v]==-1){
					q.push(v);p[v]=u;
				}
			}
		}
		if(p[snk]==-1)break;
		for(int t=snk;t!=src;t=p[t]){
			f[p[t]][t]++;
			f[t][p[t]]--;
		}
		flo++;
	}
	return flo;
}

void init(){
	mems(c,0);
	mems(f,0);
	fill(adj,adj+nmax,vector<int>());
}

void addEdge(int u,int v){
	c[u][v]=c[v][u]=1;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void TC(){
	init();
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t1,t2;
		cin>>t1>>t2;
		for(int j=t1;j<t2;j++)addEdge(i,200+j);
		int a;
		cin>>a;
		for(int j=0;j<a;j++){
			int x;cin>>x;
			addEdge(i,99+x);
		}
	}
	for(int i=0;i<100;i++){
		addEdge(301,200+i);
		addEdge(302,100+i);
	}
	sort(adj[301].begin(),adj[301].end());
	int r=nwf(301,302);
	if(r<n){
		cout<<"-1\n";
		return;
	}
	for(int i=99;i>=0;i--){
		if(f[301][200+i]){
			cout<<i+1<<"\n";
			return;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
