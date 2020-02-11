#include<bits/stdc++.h>
using namespace std;

int dp[11];

int main(void){
	for(int i=2;i<11;i++)dp[i]=dp[i/2]+dp[i-i/2]+i/2*(i-i/2);
	int n;
	cin>>n;
	cout<<dp[n];
}
