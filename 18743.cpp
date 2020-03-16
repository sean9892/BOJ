#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,k;
int dp[1000010][110];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=k;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=(i>>1)+k+1;j;j--)if((j<<1)-n<=k){
			
		}
	}
	cout<<dp[n][k];
}
