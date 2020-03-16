#include<bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int a[2][10010];
int dp[4][10010];
int n,w;

int solve(){
	dp[0][0]=0;
	dp[1][0]=a[0][0]?1:0;
	dp[2][0]=a[1][0]?1:0;
	if(a[0][0])dp[3][0]=a[0][0]+a[1][0]>w?2:1;
	else dp[3][0]=a[1][0]?1:0;
	for(int i=1;i<=n;i++){
		//
		dp[0][i]=dp[3][i-1];
		//
		dp[1][i]=dp[3][i-1]+(a[0][i]?1:0);
		if(a[0][i-1]+a[0][i]<=w)dp[1][i]=min(dp[1][i],dp[2][i-1]+1);
		//
		dp[2][i]=dp[3][i-1]+(a[1][i]?1:0);
		if(a[1][i-1]+a[1][i]<=w)dp[2][i]=min(dp[2][i],dp[1][i-1]+1);
		//
		dp[3][i]=inf;
		if(a[0][i])dp[3][i]=min(dp[3][i],dp[3][i-1]+(a[0][i]+a[1][i]>w?2:1));
		else dp[3][i]=min(dp[3][i],dp[3][i-1]+(a[1][i]?1:0));
		dp[3][i]=min({dp[3][i],dp[1][i]+(a[1][i]?1:0),dp[2][i]+(a[0][i]?1:0)});
		if(a[0][i-1]+a[0][i]<=w&&a[1][i-1]+a[1][i]<=w)dp[3][i]=min(dp[3][i],dp[0][i-1]+2);
	}
	return dp[3][n];
}

void TC(){
	memset(dp,0,sizeof(dp));
	cin>>n>>w;
	a[0][0]=a[1][0]=0;
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	int res;
	//Case1:
	res=solve();
	//Case2:
	a[0][0]=a[0][n];a[0][n]=0;
	res=min(res,solve());
	//Case3:
	a[1][0]=a[1][n];a[1][n]=0;
	res=min(res,solve());
	//Case4:
	a[0][n]=a[0][0];a[0][0]=0;
	res=min(res,solve());
	cout<<res<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
