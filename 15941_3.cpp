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

const int nmax=110;
const int vmax=1010;
const int inf=0x3f3f3f3f;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int n,m;
int val[nmax][nmax];
int vc;
int arr[nmax][nmax];
int c[vmax][vmax],f[vmax][vmax],d[vmax][vmax];
int par[vmax],dist[vmax],inq[vmax];
vector<int> g[vmax];
int vis[nmax][nmax];
vector<pii> inds,fnds;
stack<pii> sp[510];
int chk[510];
int ini[nmax][nmax];
pii pos[vmax];

int r(int u,int v){
	return c[u][v]-f[u][v];
}

pii mcmf(int src,int snk){
	int cst=0,flo=0;
	while(1){
		TEST{
			cout<<flo<<"th cycle\n";
		}
		mems(par,-1);mems(dist,0x3f);mems(inq,0);
		queue<int> q;
		par[src]=src;dist[src]=0;q.push(src);inq[src]=1;
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
			cst+=d[par[p]][p];
			f[par[p]][p]++;
			f[p][par[p]]--;
		}
		flo++;
	}
	return pii(cst,flo);
}

void addEdge(int u,int v,int cap,int dst){
	c[u][v]=cap;
	d[u][v]=dst;d[v][u]=-dst;
	g[u].push_back(v);
	g[v].push_back(u);
}

int vpos(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m;
}

int main(void){
	//ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	//IniState
	{
		int u,v;
		cin>>u>>v;
		for(int i=0;i<u;i++){
			int x,y;
			cin>>x>>y;
			val[x][y]=1;
			vc++;
			if((x&1)^(y&1)^0){
				ini[x][y]=0;
				pos[inds.size()]=pii(x,y);
				addEdge(1001,inds.size(),1,0);
				inds.emplace_back(x,y);
			}
			else{
				ini[x][y]=1;
			}
		}
		for(int i=0;i<v;i++){
			int x,y;
			cin>>x>>y;
			val[x][y]=1;
			vc++;
			if((x&1)^(y&1)^1){
				ini[x][y]=0;
				pos[inds.size()]=pii(x,y);
				addEdge(1001,inds.size(),1,0);
				inds.emplace_back(x,y);
			}
			else{
				ini[x][y]=1;
			}
		}
	}
	//FinState
	{
		int u,v;
		cin>>u>>v;
		for(int i=0;i<u;i++){
			int x,y;
			cin>>x>>y;
			if(!val[x][y]){
				cout<<-1;
				return 0;
			}
			vc--;
			if((x&1)^(y&1)^0){
				arr[x][y]=~fnds.size();
				addEdge(fnds.size()+500,1002,1,0);
				fnds.emplace_back(x,y);
			}
			else{
				arr[x][y]=2;
			}
		}
		for(int i=0;i<v;i++){
			int x,y;
			cin>>x>>y;
			if(!val[x][y]){
				cout<<-1;
				return 0;
			}
			vc--;
			if((x&1)^(y&1)^1){
				arr[x][y]=~fnds.size();
				addEdge(fnds.size()+500,1002,1,0);
				fnds.emplace_back(x,y);
			}
			else{
				arr[x][y]=1;
			}
		}
	}
	if(vc){
		cout<<-1;
		return 0;
	}
	//Build Graph
	{
		for(int s=0;s<inds.size();s++){
			int a,b;
			tie(a,b)=inds[s];
			queue<int> q;
			q.push(a);q.push(b);q.push(0);
			mems(vis,0);
			vis[a][b]=1;
			while(!q.empty()){
				int x=q.front();q.pop();
				int y=q.front();q.pop();
				int d=q.front();q.pop();
				if(arr[x][y]<0){
					addEdge(s,~arr[x][y]+500,1,d);
				}
				for(int i=0;i<4;i++){
					int nx=x+dx[i],ny=y+dy[i];
					if(vpos(nx,ny)&&!vis[nx][ny]&&arr[nx][ny]){
						q.push(nx);q.push(ny);q.push(d+1);
						vis[nx][ny]=1;
					}
				}
			}
		}
	}
	pii res=mcmf(1001,1002);
	TEST{
		cout<<res.fi<<" "<<res.se<<"\n";
	}
	cout<<res.fi<<"\n";
	//Find Shortest Path
	{
		for(int i=0;i<inds.size();i++){
			int k;
			for(k=500;k<1001;k++)if(f[i][k])break;
			TEST{
				cout<<k<<"##\n";
			}
			int a,b;
			tie(a,b)=inds[i];
			mems(vis,0);
			queue<int> q;
			q.push(a);q.push(b);
			vis[a][b]=a*101+b;
			while(!q.empty()){
				int x=q.front();q.pop();
				int y=q.front();q.pop();
				for(int i=0;i<4;i++){
					int nx=x+dx[i],ny=y+dy[i];
					if(vpos(nx,ny)&&!vis[nx][ny]&&arr[nx][ny]){
						TEST{
							cout<<"ADD "<<x<<" "<<y<<" -> "<<nx<<" "<<ny<<"\n";
						}
						vis[nx][ny]=x*101+y;
						q.push(nx);q.push(ny);
					}
				}
			}
			int x,y;
			tie(x,y)=fnds[k-500];
			for(;x!=a||y!=b;x=vis[x][y]/101,y=vis[x][y]%101){
				TEST{
					cout<<"!@# "<<x<<" "<<y<<" "<<vis[x][y]<<"\n";
				}
				sp[i].push(pii(x,y));
			}
		}
	}
	TEST{
		cout<<"Found All Shortest Path\n";
		for(int i=0;i<inds.size();i++){
			while(!sp[i].empty()){
				cout<<"("<<sp[i].top().fi<<"|"<<sp[i].top().se<<") ";
				sp[i].pop();
			}
			cout<<"\n";
		}
		return 0;
	}
	//Tracking
	{
		int cnt=inds.size();
		mems(chk,0);
		while(cnt){
			for(int i=0;i<inds.size();i++){
				if(sp[i].empty()){
					if(!chk[i]){
						chk[i]=1;
						cnt--;
					}
					continue;
				}
				while(!sp[i].empty()&&!ini[sp[i].top().fi][sp[i].top().se]){
					if(pos[i].fi==sp[i].top().fi){
						cout<<"0 "<<pos[i].fi<<" "<<sp[i].top().se<<"\n";
					}
					else{
						cout<<"1 "<<pos[i].se<<" "<<sp[i].top().fi<<"\n";
					}
					pos[i]=sp[i].top();
					sp[i].pop();
				}
			}
		}
	}
}
