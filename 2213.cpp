#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

const int nmax = 10010;

int n;
int v[nmax];
vector<int> adj[nmax];
int dp[nmax][2];
vector<int> vtx[nmax][2];

//Tree DP
void f(int now,int pre){
	dp[now][1]=v[now];
	vtx[now][1].push_back(now);
	for(int i:adj[now])if(i!=pre){
		f(i,now);
		if(dp[i][0]>dp[i][1]){
			dp[now][0]+=dp[i][0];
			vtx[now][0].insert(vtx[now][0].end(),all(vtx[i][0]));
		}
		else{
			dp[now][0]+=dp[i][1];
			vtx[now][0].insert(vtx[now][0].end(),all(vtx[i][1]));
		}
		dp[now][1]+=dp[i][0];
		vtx[now][1].insert(vtx[now][1].end(),all(vtx[i][0]));
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	f(1,-1);
	cout<<max(dp[1][0],dp[1][1])<<"\n";
	if(dp[1][0]>dp[1][1]){
		sort(all(vtx[1][0]));
		for(int i:vtx[1][0])cout<<i<<" ";
	}
	else{
		sort(all(vtx[1][1]));
		for(int i:vtx[1][1])cout<<i<<" ";
	}
}
