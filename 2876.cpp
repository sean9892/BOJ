#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

pii dp[100010][2];
int arr[100010][2];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	cin>>arr[0][0]>>arr[0][1];
	dp[0][0]=pii(-1,arr[0][0]);
	dp[0][1]=pii(-1,arr[0][1]);
	pii r=min(dp[0][0],dp[0][1]);
	for(int i=1;i<n;i++){
		cin>>arr[i][0]>>arr[i][1];
		for(int j=0;j<2;j++){
			dp[i][j]=pii(-1,arr[i][j]);
			for(int k=0;k<2;k++){
				if(arr[i][j]==arr[i-1][k]){
					int x=dp[i-1][k].first,y=dp[i-1][k].second;
					dp[i][j]=min(dp[i][j],pii(x-1,y));
				}
			}
			r=min(r,dp[i][j]);
		}
	}
	cout<<-r.first<<" "<<r.second;
}
