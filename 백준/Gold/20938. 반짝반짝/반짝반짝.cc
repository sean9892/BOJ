#include<bits/stdc++.h>
using namespace std;
using dtype = long double;

int N,K;
dtype p[2510];
dtype E[2510][2510];
dtype dp[2510][19];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>p[i];
        dtype res = 0;
        for(int j=i;j>0;j--){
            res = (1-p[j])*(1+res);
            E[j][i] = res;
        }
    }
    for(int i=1;i<=N;i++)dp[i][1]=E[i][N];
    for(int k=2;k<=K;k++){
        dp[N][K]=E[N][N];
        for(int i=N-1;i>0;i--){
            dtype res = 0;
            for(int j=i+1;j<=N;j++){
                res=max(res,dp[j][k-1]+E[i][j-1]);
            }
            dp[i][k]=res;
        }
    }
    dtype res = 0;
    for(int i=1;i<=K;i++)res=max(res,dp[1][i]);
    cout<<fixed<<setprecision(12)<<res;
}