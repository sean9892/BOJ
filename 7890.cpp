#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using dot=pair<ll,ll>;
#define fi first
#define se second
const int nmax=1e5+10;
const int inf=0x3f3f3f3f;
dot operator-(dot a,dot b){
    return {a.fi-b.fi,a.se-b.se};
}
ll eDist(dot a,dot b){
    dot c=a-b;
    return c.fi*c.fi+c.se*c.se;
}
struct cmp{
    bool k;
    cmp(bool x):k(x){}
    bool operator()(dot x,dot y){
        return (k?x.se:x.fi)<(k?y.se:y.fi);
    }
};
struct node{
    ll val;
    int le,ri;
    dot p;
};
struct KDTREE{
    dot v[100010];
    node tree[200010];
    int cnt=0;
    int mktree(int s,int e,bool d){
    	if(s>e)return -1;
        int idx=cnt++;
        if(s==e){
            tree[idx]={(d?v[s].se:v[s].fi),-1,-1,v[s]};
            return idx;
        }
        sort(v+s,v+e+1,cmp(d));
        int m=s+e>>1;
        tree[idx]={(d?v[m].se:v[m].fi),-1,-1,v[m]};
        int x=mktree(s,m-1,!d),y=mktree(m+1,e,!d);
        tree[idx].le=x;tree[idx].ri=y;
        return idx;
    }
    ll mdst=5e18;
    void nns(int idx,dot p,bool d){
    	node nd=tree[idx];
    	if(p!=nd.p)mdst=min(eDist(nd.p,p),mdst);
    	if(nd.le==-1&&nd.ri==-1)return;
    	#define t (d?p.se:p.fi)
		if(t<=nd.val){
			if(nd.le!=-1)nns(nd.le,p,!d);
			if(nd.ri!=-1&&(t-nd.val>=0||(t-nd.val)<=mdst))nns(nd.ri,p,!d);
		}
		else{
			if(nd.ri!=-1)nns(nd.ri,p,!d);
			if(nd.le!=-1&&(t+nd.val)*(t+nd.val)<=mdst)nns(nd.le,p,!d);
		}
		#undef t
    }
};

set<dot> s;
set<dot> doub;///Doubled Point
dot v[100010];

void TC(){
	s.clear();
	doub.clear();
    KDTREE kdt;
    int n;
    cin>>n;
    int c=0;
    kdt.cnt=0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[i]=dot(x,y);
        if(s.find(v[i])!=s.end())doub.insert(dot(x,y));
        else kdt.v[c++]=dot(x,y);
        s.insert(dot(x,y));
    }
    kdt.mktree(0,c-1,false);
    for(int i=0;i<n;i++){
        if(doub.find(v[i])==doub.end()){
        	kdt.mdst=5e18;
        	kdt.nns(0,v[i],0);
            cout<<kdt.mdst<<"\n";
        }
        else{
            cout<<"0\n";
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        TC();
    }
}
