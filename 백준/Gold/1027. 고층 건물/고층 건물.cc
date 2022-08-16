#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll arr[99];

ll f(int i,int j,int k){
    ll a=arr[i],b=arr[j],c=arr[k];
    return (b-a)*(k-i)+(a-c)*(j-i);
}

int vis[99][99];

int32_t main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vis[i][j]=vis[j][i]=1;
            for(int k=i+1;k<j;k++){
                vis[i][j]&=(f(i,j,k)>0);
                vis[j][i]&=(f(i,j,k)>0);
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            cnt+=vis[i][j];
        }
        mx=max(mx,cnt);
    }
    cout<<mx;
}