#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pli=pair<ll,int>;
#define fi first
#define se second

const ll MOD = 1e9+7;

int sv[10101010];
ll ps[1000000];
ll e[1000000];
ll res[50010];
vector<pli> q;
vector<ll> diff[50010];
int pc=0;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<10000000;i++){
        if(sv[i])continue;
        ps[pc]=i;
        e[pc]=1;
        pc++;
        for(int j=i*2;j<10000000;j+=i){
            sv[j]=1;
        }
    }
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        ll x;
        cin>>x;
        q.emplace_back(x,i);
    }
    sort(q.begin(),q.end());
    for(int i=0;i<pc;i++){
        for(ll j=ps[i]*ps[i];j<=q.back().fi;j*=ps[i]){
            int idx = lower_bound(q.begin(),q.end(),pli(j,0))-q.begin();
            if(idx==T)break;
            diff[idx].push_back(ps[i]);
            if(q.back().fi/j<ps[i])break;
        }
    }
    ll r=1;
    for(int i=0;i<T;i++){
        for(ll j:diff[i]){
            r*=j;
            r%=MOD;
        }
        res[q[i].se]=r;
    }
    for(int i=1;i<=T;i++){
        cout<<"Case "<<i<<": "<<res[i]<<"\n";
    }
}