#include<bits/stdc++.h>
using namespace std;

int n;
int v[10010];//마을 주민 수 
//dp[i][0]: i번째 마을을 지정 안 할 때의 서브트르의 최대 주민 수 합
//dp[i][1]: i번째 마을을 지정할 때의 서브트리의 최대 주민 수 합 
int dp[10010][2];
vector<int> adj[10010];

void f(int now,int pre){
	dp[now][1]=v[now];
	for(int i:adj[now])if(i!=pre){
		f(i,now);
		dp[now][0]+=max(dp[i][0],dp[i][1]);
		dp[now][1]+=dp[i][0];
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
	cout<<max(dp[1][0],dp[1][1]);
}
