#include<bits/stdc++.h>
using namespace std;

int nA,nB;
int M;
int edge[1010][1010];
int dp[1010][1010];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>nA>>nB;
    cin>>M;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        edge[x][y]=1;
    }
    int res=0;
    for(int i=0;i<=nA;i++){
        for(int j=0;j<=nB;j++){
            if(edge[i][j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            if(i>=2)dp[i][j]=max(dp[i][j],dp[i-2][j]+1);
            if(j>=2)dp[i][j]=max(dp[i][j],dp[i][j-2]+1);
            if(i>=2&&j>=2)dp[i][j]=max(dp[i][j],dp[i-2][j-2]+2);
            res = max(res,dp[i][j]);
        }
    }
    cout<<res;
}