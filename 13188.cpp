#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,s,f;
const ll mod=1e9+7;
ll dp[2010][2010];
ll solve(int i,int j){
	if(j==0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(i==1)return j==1;
	if(i==s||i==f)return dp[i][j]=(solve(i-1,j-1)+solve(i-1,j))%mod;
	return dp[i][j]=(solve(i-1,j-1)*(j-(s<i)-(f<i))+solve(i-1,j+1)*j)%mod;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>s>>f;
	cout<<solve(n,1);
}
