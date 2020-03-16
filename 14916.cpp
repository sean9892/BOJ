#include<bits/stdc++.h>
using namespace std;

int dp[100010];

int main(void){
	memset(dp,0x3f,sizeof(dp));
	dp[2]=dp[5]=1;
	dp[4]=2;
	for(int i=6;i<100001;i++){
		dp[i]=min(min(dp[i-2],dp[i-5])+1,0x3f3f3f3f);
	}
	int n;
	cin>>n;
	if(dp[n]==0x3f3f3f3f)cout<<-1;
	else cout<<dp[n];
}
