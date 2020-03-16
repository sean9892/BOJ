#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>> g;
set<string> vis;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(c);
	}
	if(g.find("Baba")!=g.end()){
		queue<string> q;
		q.push("Baba");
		vis.insert("Baba");
		vector<string> v;
		while(!q.empty()){
			string s=q.front();q.pop();
			v.push_back(s);
			if(g.find(s)!=g.end()){
				for(string t:g[s]){
					if(vis.find(t)!=vis.end())continue;
					vis.insert(t);
					q.push(t);
				}
			}
		}
		sort(v.begin()+1,v.end());
		for(int i=1;i<v.size();i++){
			cout<<v[i]<<"\n";
		}
	}
}
