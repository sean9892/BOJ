#include<bits/stdc++.h>
using namespace std;
using edge=pair<int,int>;
using pii=pair<int,int>;
#define fi first
#define se second

const int inf=0x3f3f3f3f;
vector<edge> g[1010];
priority_queue<int> dist[1010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].emplace_back(b,c);
	}
	for(int i=2;i<=n;i++)dist[i].push(inf);
	dist[1].push(0);
	priority_queue<pii> q;
	q.push(pii(-0,1));
	while(!q.empty()){
		int t,d;
		tie(d,t)=q.top();q.pop();
		d=-d;
		if(d>dist[t].top())continue;
		for(auto x:g[t]){
			int i,w;
			tie(i,w)=x;
			if(dist[i].size()<k){
				dist[i].push(d+w);
				q.push(pii(-d-w,i));
			}
			else if(dist[i].top()>d+w){
				dist[i].push(d+w);
				dist[i].pop();
				q.push(pii(-d-w,i));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i].size()<k||dist[i].top()==inf){
			cout<<"-1\n";
		}
		else{
			cout<<dist[i].top()<<"\n";
		}
	}
}
