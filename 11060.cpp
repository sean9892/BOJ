#include<bits/stdc++.h>
using namespace std;

int dp[1010];
int arr[1010];

int main(void){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	dp[n]=0;
	for(int i=n-1;i>0;i--){
		dp[i]=987654321;
		for(int j=i+1;j-i<=arr[i]&&j<=n;j++){
			dp[i]=min(dp[i],dp[j]+1);
		}
	}
	cout<<(dp[1]>=987654321?-1:dp[1]);
}
