#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

#define fi first
#define se second

const int inf = 0x3f3f3f3f;

const int LOVE = 0;
const int HATE = 1;

int n,m;
int tab[110][110];
int arr[110][110];
int gidx[110][110];
int cnt;
vector<int> g[510];
vector<pii> nds;
int c[510][510];
int f[510][510];

int p[510],dist[510];

void addEdge(int u,int v,int flo){
	c[u][v]=flo;
	
}

int vpos(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(tab,-1,sizeof(tab));
	memset(gidx,-1,sizeof(gidx));
	cin>>n>>m;
	int u,v;
	cin>>u>>v;
	nds.emplace_back(-1,-1);
	for(int i=0;i<u;i++){
		int a,b;
		cin>>a>>b;
		tab[a][b]=LOVE;
		if((a+b)&1)tab[a][b]^=1;
		gidx[a][b]=++cnt;
		nds.emplace_back(a,b);
	}
	for(int i=0;i<v;i++){
		int a,b;
		cin>>a>>b;
		tab[a][b]=HATE;
		if((a+b)&1)tab[a][b]^=1;
		gidx[a][b]=++cnt;
		nds.emplace_back(a,b);
	}
	cin>>u>>v;
	for(int i=0;i<u;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]=LOVE;
		if((a+b)&1)arr[a][b]^=1;
	}
	for(int i=0;i<v;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]=HATE;
		if((a+b)&1)arr[a][b]^=1;
	}
	for(int i=1;i<nds.size();i++){
		int x=nds[i].fi,y=nds[i].se;
		if(tab[x][y]==LOVE){
			addEdge(501,i,1);
		}
		if(arr[x][y]==LOVE){
			addEdge(502,i,1);
		}
		for(int dx=x,dy=y+1;dx<x+2;dx++,dy--){
			if(vpos(dx,dy)&&gidx[dx][dy]!=-1){
				addEdge(i,gidx[dx][dy],inf);
			}
		}
	}
}
