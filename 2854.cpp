#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[100010][2];
ll a[100010];
ll b[100010];
const ll mod=1e9+7;
int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][0]*(a[i]+b[i-1])+dp[i-1][1]*(a[i]+b[i-1]-1))%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])*b[i]%mod;
	}
	cout<<dp[n][0];
}
