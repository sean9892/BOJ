#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+10;

int n;
vector<int> adj[nmax];
int dp[nmax][19];

void f(int now,int pre,int col){
    if(dp[now][col])return;
    dp[now][col]=col;
    for(int i:adj[now])if(i!=pre){
        int mv=2e9;
        for(int c=1;c<=18;c++)if(c!=col){
            f(i,now,c);
            mv=min(mv,dp[i][c]);
        }
        dp[now][col]+=mv;
    }
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mv=2e9;
    for(int i=1;i<=18;i++){
        f(1,-1,i);
        mv=min(mv,dp[1][i]);
    }
    cout<<mv;
}
