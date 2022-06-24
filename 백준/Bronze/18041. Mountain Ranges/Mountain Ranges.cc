#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[9999];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res = 1;
    int dp[9999];
    fill(dp,dp+n,1);
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]<=k){
            dp[i]=dp[i-1]+1;
            res=max(res,dp[i]);
        }
    }
    cout<<res;
}