#define DEBUG

#ifdef DEBUG
#define TEST if(1)
#else
#define TEST if(0)
#endif

#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

#define fi first
#define se second

#define mems(x,v) memset(x,v,sizeof(x))

const int LOVE = 0;
const int HATE = 1;
const int nmax = 1010;
const int inf  = 0x3f3f3f3f;

int n,m;
vector<int> g[nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int d[nmax][nmax];
vector<pii> inds,fnds;//Nodes of Initial/Final State
int par[nmax],dist[nmax];
int inq[nmax];
int fmp[110][110];
int vis[110][110];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int eDist(pii a,pii b){
	return abs(a.fi-b.fi)+abs(a.se-b.se);
}

void addEdge(int u,int v,int cap,int dst){
	g[u].push_back(v);
	g[v].push_back(u);
	c[u][v]=cap;
	d[u][v]=dst;d[v][u]=-dst;
}

int r(int u,int v){
	return c[u][v]-f[u][v];
}

int mcmf(int src,int snk){
	int dst=0;
	while(1){
		mems(par,-1);
		mems(dist,0x3f);
		mems(inq,0);
		queue<int> q;
		par[src]=src;
		dist[src]=0;
		inq[src]=1;
		q.push(src);
		while(!q.empty()){
			int t=q.front();q.pop();
			TEST{
				cout<<"# "<<t<<"\n";
			}
			inq[t]=0;
			for(int i:g[t]){
				if(r(t,i)>0&&dist[i]>dist[t]+d[t][i]){
					dist[i]=dist[t]+d[t][i];
					par[i]=t;
					if(!inq[i]){
						q.push(i);
						inq[i]=1;
					}
				}
			}
		}
		if(par[snk]==-1)break;
		for(int p=snk;p!=src;p=par[p]){
			TEST{
				cout<<"$ "<<p<<"\n";
			}
			dst++;
			f[par[p]][p]++;
			f[p][par[p]]--;
		}
	}
	return dst;
}

int vpos(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m;
}

int main(void){
	//ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	//Initial State
	{
		TEST{
			cout<<"[Initial State]\n";
		}
		int u,v;
		cin>>u>>v;
		for(int i=0;i<u;i++){
			int a,b;
			cin>>a>>b;
			if(a^1&b^1&LOVE){
				inds.emplace_back(a,b);
			}
		}
		for(int i=0;i<u;i++){
			int a,b;
			cin>>a>>b;
			if(a^1&b^1&HATE){
				inds.emplace_back(a,b);
			}
		}
	}
	//Final State
	{
		TEST{
			cout<<"[Final State]\n";
		}
		mems(fmp,0x3f);
		int u,v;
		cin>>u>>v;
		for(int i=0;i<u;i++){
			int a,b;
			cin>>a>>b;
			if(a^1&b^1&LOVE){
				fmp[a][b]=fnds.size();
				fnds.emplace_back(a,b);
			}
			else{
				fmp[a][b]=-1;
			}
		}
		for(int i=0;i<u;i++){
			int a,b;
			cin>>a>>b;
			if(a^1&b^1&HATE){
				fmp[a][b]=fnds.size();
				fnds.emplace_back(a,b);
			}
			else{
				fmp[a][b]=-1;
			}
		}
	}
	//Build Graph
	{
		TEST{
			cout<<"[Build Graph]\n";
		}
		for(int i=0;i<inds.size();i++){
			cout<<"$"<<i<<"\n";
			queue<int> q;
			mems(vis,0);
			q.push(inds[i].fi);q.push(inds[i].se);q.push(0);
			vis[inds[i].fi][inds[i].se]=1;
			while(!q.empty()){
				int x=q.front();q.pop();
				int y=q.front();q.pop();
				int dst=q.front();q.pop();
				TEST{
					cout<<x<<" "<<y<<" "<<dst<<" ";
				}
				if(fmp[x][y]!=-1&&fmp[x][y]!=inf){
					addEdge(i,fmp[x][y]+500,1,1);
				}
				TEST{
					cout<<"$\n";
				}
				for(int i=0;i<4;i++){
					int nx=x+dx[i],ny=y+dy[i];
					if(vpos(nx,ny)&&!vis[nx][ny]&&fmp[nx][ny]!=inf){
						vis[nx][ny]=1;
						q.push(nx);
						q.push(ny);
						q.push(dst+1);
					}
				}
			}
		}
		for(int i=0;i<inds.size();i++){
			addEdge(1001,i,1,0);
		}
		for(int i=0;i<fnds.size();i++){
			addEdge(i+500,1002,1,0);
		}
	}
	TEST{
		cout<<"MCMF\n";
	}
	cout<<mcmf(1001,1002);
}
