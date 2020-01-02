#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using pi3=pair<int,pii>;

#define mems(x,v) memset(x,v,sizeof(x))

const int inf=0x3f3f3f3f;
const unsigned char inf_MS = 0x3f;

const int nmax=100010;

int n;
int ap,bp,cp;
vector<pii> adj[nmax];
int d[3][nmax];

//Dijkstra -- //
void dijkstra(int s,int wr){
	mems(d[wr],inf_MS);
	priority_queue<pii> q;
	q.push(pii(0,s));
	while(!q.empty()){
		auto [w,t]=q.top();q.pop();
		w*=-1;
		if(w>d[wr][t])continue;
		d[wr][t]=w;
		for(auto [i,v]:adj[t])if(d[wr][i]>d[wr][t]+v){
			d[wr][i]=d[wr][t]+v;
			q.push(pii(-d[wr][i],i));
		}
	}
}
// -- //

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cin>>ap>>bp>>cp;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].push_back(pii(y,z));
		adj[y].push_back(pii(x,z));
	}
	dijkstra(ap,0);
	dijkstra(bp,1);
	dijkstra(cp,2);
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++)cout<<d[i][j]<<" ";
		cout<<"\n";
	}
}
