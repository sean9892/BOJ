#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[30][30];
int par[999];
int val[999];

int fnd(int u){
    if(par[u]<0)return u;
    return par[u]=fnd(par[u]);
}

int mer(int u,int v){
    u=fnd(u);v=fnd(v);
    if(u==v)return 0;
    par[u]=v;
    return 1;
}

int idx(int x,int y){
    return x*30+y;
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(i&&arr[i-1][j]==arr[i][j])mer(idx(i-1,j),idx(i,j));
            if(j&&arr[i][j-1]==arr[i][j])mer(idx(i,j-1),idx(i,j));
        }
    }
    int chg = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            int t=fnd(idx(i,j));
            if(val[t]==0){
                if(chg&&arr[i][j]!=x){
                    cout<<"NO";
                    return 0;
                }
                if(arr[i][j]!=x)chg = 1;
                val[t]=x;
            }
            else if(val[t]!=x){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}