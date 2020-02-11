#include<bits/stdc++.h>
using namespace std;

vector<int> adj[30];

void dfs1(int x){
	cout<<(char)(x+'A'-1);
	if(adj[x][0])dfs1(adj[x][0]);
	if(adj[x][1])dfs1(adj[x][1]);
}
void dfs2(int x){
	if(adj[x][0])dfs2(adj[x][0]);
	cout<<(char)(x+'A'-1);
	if(adj[x][1])dfs2(adj[x][1]);
}
void dfs3(int x){
	if(adj[x][0])dfs3(adj[x][0]);
	if(adj[x][1])dfs3(adj[x][1]);
	cout<<(char)(x+'A'-1);
}

int main(void){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b,c;
		cin>>a>>b>>c;
		int x,y,z;
		x=a-'A'+1;
		y=b=='.'?0:b-'A'+1;
		z=c=='.'?0:c-'A'+1;
		adj[x].push_back(y);
		adj[x].push_back(z);
	}
	dfs1(1);cout<<"\n";
	dfs2(1);cout<<"\n";
	dfs3(1);cout<<"\n";
}
