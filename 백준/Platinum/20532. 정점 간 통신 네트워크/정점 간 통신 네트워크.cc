#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll c[100010],d[100010];
int p[100010];
int a[100010];
vector<int> g[100010];

ll f(int u){
    ll res = -c[a[u]];
    res+=d[a[u]];
    for(int i=1;i*i<=a[u];i++){
        if(a[u]%i==0){
            res+=c[i];
            if(i*i!=a[u])res+=c[a[u]/i];
            d[i]++;
            if(i*i!=a[u])d[a[u]/i]++;
        }
    }
    c[a[u]]++;
    for(int v:g[u]){
        res+=f(v);
    }
    c[a[u]]--;
    for(int i=1;i*i<=a[u];i++){
        if(a[u]%i==0){
            d[i]--;
            if(i*i!=a[u])d[a[u]/i]--;
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        cin>>p[i];
        g[p[i]].push_back(i);
    }
    cout<<f(1);
}