#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second

#define int ll

const ll MOD = 998244353;

int N,Q;
vector<pii> qrs[300010];
int nxt[300010];
int prv[300010];
ll c[300010];

int32_t main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>Q;
    for(int i=1;i<=Q;i++){
        int l,r;
        cin>>l>>r>>c[i];
        qrs[l].emplace_back(+1,i);
        qrs[r+1].emplace_back(-1,i);
    }
    c[0]=c[Q+1]=0;
    set<int> s;
    s.insert(0);
    s.insert(Q+1);
    prv[Q+1]=0;
    nxt[0]=Q+1;
    ll now = 0;
    ll res = 0;
    for(int i=1;i<=N;i++){
        sort(qrs[i].begin(),qrs[i].end());
        for(auto k:qrs[i]){
            int t,idx;
            tie(t,idx) = k;
            if(t==1){
                int NXT = *s.upper_bound(idx);
                int PRV = *prev(s.lower_bound(idx));
                s.insert(idx);
                nxt[PRV] = idx;
                prv[NXT] = idx;
                nxt[idx] = NXT;
                prv[idx] = PRV;
                now += MOD - (NXT-idx)*PRV%MOD*c[PRV]%MOD;
                now %= MOD;
                now += (NXT-idx)*idx%MOD*c[idx]%MOD;
                now %= MOD;
            }
            else{
                int NXT = nxt[idx];
                int PRV = prv[idx];
                s.erase(idx);
                nxt[PRV] = NXT;
                prv[NXT] = PRV;
                now += (NXT-idx)*PRV%MOD*c[PRV]%MOD;
                now %= MOD;
                now += MOD - (NXT-idx)*idx%MOD*c[idx]%MOD;
                now %= MOD;
            }
        }
        res += now*i%MOD*(N-i+1)%MOD;
        res %= MOD;
    }
    cout<<res;
}