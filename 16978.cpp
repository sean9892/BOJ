#include<bits/stdc++.h>
using ll=long long;
#define int ll
using namespace std;
using pii=pair<int,int>;
using Query=pair<int,pair<int,pii>>;

#define fi first
#define se second

const int nmax=100010;

int n;
int res[nmax];
vector<pii> sqv;
vector<Query> qv;
int seg[nmax<<2];

void upd(int idx,int l,int r,int p,int v){
    if(l>p||r<p)return;
    if(l!=r){
        int m=l+r>>1;
        int le=idx<<1,ri=le+1;
        upd(le,l,m,p,v);
        upd(ri,m+1,r,p,v);
        seg[idx]=seg[le]+seg[ri];
        return;
    }
    seg[idx]=v;
}

int query(int idx,int l,int r,int s,int e){
    if(l>e||r<s)return 0;
    if(s<=l&&r<=e)return seg[idx];
    int m=l+r>>1;
    int le=idx<<1,ri=le+1;
    return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

#undef int
int main(void){
    #define int ll
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        upd(1,1,n,i,t);
    }
    int m;
    cin>>m;
    int cc=0;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            sqv.emplace_back(a,b);
        }
        else{
            int a,b,c;
            cin>>a>>b>>c;
            qv.push_back(Query(a,pair<int,pii>(cc++,pii(b,c))));
        }
    }
    sort(qv.begin(),qv.end());
    int p=0;
    while(p<m&&qv[p].fi==0){
        res[qv[p].se.fi]=query(1,1,n,qv[p].se.se.fi,qv[p].se.se.se);
        ++p;
    }
    for(int i=0;i<sqv.size();i++){
        upd(1,1,n,sqv[i].fi,sqv[i].se);
        while(p<m&&qv[p].fi==i+1){
            res[qv[p].se.fi]=query(1,1,n,qv[p].se.se.fi,qv[p].se.se.se);
            ++p;
        }
    }
    for(int i=0;i<cc;i++){
        cout<<res[i]<<"\n";
    }
}
