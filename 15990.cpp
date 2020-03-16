#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+9;
ll dp[100010][4];

void TC(){
	ll n;
	cin>>n;
	cout<<(dp[n][1]+dp[n][2]+dp[n][3])%mod<<"\n";
}

int main(void){
	dp[1][1]=1;
	dp[2][2]=1;
	dp[3][1]=1;dp[3][2]=1;dp[3][3]=1;
	for(ll i=4;i<100010;i++){
		dp[i][1]=(dp[i-1][2]+dp[i-1][3])%mod;
		dp[i][2]=(dp[i-2][1]+dp[i-2][3])%mod;
		dp[i][3]=(dp[i-3][1]+dp[i-3][2])%mod;
	}
	ios::sync_with_stdio(0);cin.tie(0);
	ll tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
