#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using pi3=tuple<int,int,int>;
vector<pii> adj[110];
pii dist[110];
pii operator+(pii a,pii b){
	return {a.first+b.first,a.second+b.second};
}
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,r;
	cin>>n>>r;
	for(int i=0;i<r;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		int cst=c+max(e-10,0)*d;
		adj[a].emplace_back(b,cst);
	}
	priority_queue<pi3> q;
	fill(dist,dist+110,pii(987654321,987654321));
	q.emplace(0,-1,1);
	while(!q.empty()){
		int t,w,c;
		tie(w,c,t)=q.top();q.pop();
		w=-w;c=-c;
		if(dist[t]<pii(w,c))continue;
		dist[t]=pii(w,c);
		for(pii x:adj[t]){
			int i,d;
			tie(i,d)=x;
			if(dist[i]>dist[t]+pii(d,1)){
				dist[i]=dist[t]+pii(d,1);
				int a,b;tie(a,b)=dist[i];
				q.emplace(-a,-b,i);
			}
		}
	}
	if(dist[n]==pii(987654321,987654321)){
		cout<<"It is not a great way.";
		return 0;
	}
	int a,b;tie(a,b)=dist[n];
	cout<<a<<" "<<b;
}
