#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

// 1~n : Team A
// n+1~n+m : Team B
// n+m+1 : src
// n+m+2 : snk

int n,m;
int arr[99];
int brr[99];
int c[999][999];
int f[110][110];
vector<int> g[110];
int p[110];

int r(int u,int v){
    return c[u][v]-f[u][v];
}

int nwf(int src,int snk){
    int flo=0;
    while(1){
        memset(p,-1,sizeof(p));
        queue<int> q;
        q.push(src);
        p[src]=src;
        while(!q.empty()&&p[snk]==-1){
            int t=q.front();q.pop();
            for(int i:g[t]){
                if(r(t,i)>0&&p[i]==-1){
                    p[i]=t;
                    q.push(i);
                }
            }
        }
        if(p[snk]==-1)break;
        for(int i=snk;i!=src;i=p[i]){
            f[p[i]][i]++;
            f[i][p[i]]--;
        }
        flo++;
    }
    return flo;
}

void upd(int src,int snk){
    memset(p,-1,sizeof(p));
    queue<int> q;
    q.push(src);
    p[src]=src;
    while(!q.empty()&&p[snk]==-1){
        int t=q.front();q.pop();
        for(int i:g[t]){
            if(t<src||(t==src&&i<snk))continue;
            if(r(t,i)>0&&p[i]==-1){
                q.push(i);
                p[i]=t;
            }
        }
    }
    if(p[snk]==-1)return;
    f[src][snk]=f[snk][src]=0;
    for(int i=snk;i!=src;i=p[i]){
        f[p[i]][i]++;
        f[i][p[i]]--;
    }
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    const int SRC = n+m+1;
    const int SNK = n+m+2;
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        s+=arr[i];
        c[SRC][i]=arr[i];
        g[SRC].push_back(i);
        g[i].push_back(SRC);
    }
    int _s=s;
    for(int i=1;i<=m;i++){
        cin>>brr[i];
        _s-=brr[i];
        c[n+i][SNK]=brr[i];
        g[n+i].push_back(SNK);
        g[SNK].push_back(n+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][n+j]=1;
            g[i].push_back(n+j);
            g[n+j].push_back(i);
        }
    }
    if(_s!=0){
        cout<<"-1";
        return 0;
    }
    int flo=nwf(SRC,SNK);
    if(flo<s){
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][n+j]!=1)continue;
            upd(i,n+j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<f[i][n+j];
        }
        cout<<"\n";
    }
}