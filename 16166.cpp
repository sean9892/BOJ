#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> v;
vector<int> adj[11];
set<int> es;

int vis[11];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;cin>>x;
			v[x].push_back(i);
			adj[i].push_back(x);
		}
	}
	int e;
	cin>>e;
	for(int i:v[e])es.insert(i);
	queue<int> q;
	for(int i:v[0])q.push(i),q.push(0);
	while(!q.empty()){
		int t=q.front();q.pop();
		int d=q.front();q.pop();
		if(es.find(t)!=es.end()){
			cout<<d;
			return 0;
		}
		for(int i:adj[t]){
			for(int j:v[i]){
				if(!vis[j]){
					vis[j]=1;
					q.push(j);q.push(d+1);
				}
			}
		}
	}
	cout<<-1;
}
