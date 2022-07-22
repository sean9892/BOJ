#include<bits/stdc++.h>
using namespace std;

//fastio
#define fastio ios::sync_with_stdio(0);cin.tie(0);

//macro funx
#define mems(x,v) memset(x,v,sizeof(x))

//Pair
using pii=pair<int,int>;
#define f first
#define s second

//Constant
#define NMAX 200010

int n,k,res=1e9;
int sz[NMAX], vis[NMAX];
vector<pii> adj[NMAX];
map<int,int> mp; //mp[x] : min edge cnt of way(dist=x)

int getSz(int now,int pre){
	sz[now]=1;
	for(pii i:adj[now]){
		if(pre==i.f||vis[i.f])continue;
		sz[now]+=getSz(i.f,now);
	}
	return sz[now];
}

int fndCen(int now,int pre,int cap){
	for(pii i:adj[now]){
		if(pre==i.f||vis[i.f])continue;
		if(sz[i.f]>cap)return fndCen(i.f,now,cap);
	}
	return now;
}

void fndAns(int now,int pre,int dst,int dep){
	if(dst>k)return;
	auto it=mp.find(k-dst);
	if(it!=mp.end())res=min(it->s+dep,res);
	for(pii i:adj[now]){
		if(pre==i.f||vis[i.f])continue;
		fndAns(i.f,now,dst+i.s,dep+1);
	}
}

void mer(int now,int pre,int dst,int dep){
	if(dst>k)return;
	auto it=mp.find(dst);
	if(it==mp.end()){
		mp[dst]=dep;
	}
	else{
		it->s=min(it->s,dep);
	}
	for(pii i:adj[now]){
		if(pre!=i.f&&!vis[i.f])mer(i.f,now,dst+i.s,dep+1);
	}
}

void solve(int now){
	int cap=getSz(now,-1)/2;
	int cen=fndCen(now,-1,cap);
	mp.clear();mp[0]=0;
	vis[cen]=1;
	for(pii i:adj[cen]){
		if(!vis[i.f]){
			fndAns(i.f,cen,i.s,1);
			mer(i.f,cen,i.s,1);
		}
	}
	for(pii i:adj[cen]){
		if(!vis[i.f])solve(i.f);
	}
}

int main(void){
	fastio;
	
	mems(sz,0);mems(vis,0);
	
	
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	solve(0);
	if(res>=1e9){
		cout<<-1;
	}
	else{
		cout<<res;
	}
	return 0;
}