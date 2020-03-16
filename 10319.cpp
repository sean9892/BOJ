#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int v,cap,rev;
	Edge(int v,int cap,int rev):v(v),cap(cap),rev(rev){}
};

struct Dinic{
	int n;
	vector<vector<Edge>> vt;
	vector<int> lvl,nxt;
	Dinic(int n):n(n){
		vt.resize(n+1);
	}
	void addEdge(int s,int e,int c){
		vt[s].emplace_back(e,c,(int)vt[e].size());
		vt[e].emplace_back(s,0,(int)vt[s].size()-1);
	}
	int bfs(int src,int snk){
		lvl.assign(n+1,-1);
		lvl[src]=0;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto i:vt[u]){
				int v=i.v,cap=i.cap;
				if(cap&&lvl[v]==-1){
					lvl[v]=lvl[u]+1;
					q.push(v);
				}
			}
		}
		return lvl[snk]!=-1;
	}
	int dfs(int u,int crt,int to){
		if(u==to)return crt;
		for(int &i=nxt[u];i<vt[u].size();i++){
			int v=vt[u][i].v,cap=vt[u][i].cap;
			if(cap&&lvl[u]+1==lvl[v]){
				int flo=dfs(v,min(crt,cap),to);
				if(flo){
					vt[u][i].cap-=flo;
					vt[v][vt[u][i].rev].cap+=flo;
					return flo;
				}
			}
		}
		return 0;
	}
	int get(int a,int b){
		int flo=0;
		while(bfs(a,b)){
			nxt.assign(n+1,0);
			while(1){
				int f=dfs(a,0x3f3f3f3f,b);
				if(!f)break;
				flo+=f;
			}
		}
		return flo;
	}
};

void TC(){
	int n,src,g,s;
	cin>>n>>src>>g>>s;
	Dinic dn((n+1)*(s+1)+5);
	dn.addEdge((n+1)*(s+1)+1,src*(s+1),g);
	for(int v=1;v<=n;v++)
		for(int t=0;t<s;t++)
			dn.addEdge(v*(s+1)+t,v*(s+1)+t+1,0x3f3f3f3f);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		dn.addEdge(x*(s+1)+s,(n+1)*(s+1)+2,0x3f3f3f3f);
	}
	int r;
	cin>>r;
	for(int i=0;i<r;i++){
		int a,b,p,t;
		cin>>a>>b>>p>>t;
		for(int i=0;i+t<=s;i++)
			dn.addEdge(a*(s+1)+i,b*(s+1)+i+t,p);
	}
	cout<<dn.get((s+1)*(n+1)+1,(s+1)*(n+1)+2)<<"\n";
	
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
