#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define fi first
#define se second

#define fastio do{ios::sync_with_stdio(0);cin.tie(0);}while(0)

const int nmax=2000010;
const ll inf=987654321;
pii seg[nmax<<2];
int res[nmax];

void f(int idx,int op,ll v){
	if(op==1){
		seg[idx].fi=max(seg[idx].fi,v);
		seg[idx].se=max(seg[idx].se,v);
	}
	else{
		seg[idx].fi=min(seg[idx].fi,v);
		seg[idx].se=min(seg[idx].se,v);
	}
}

void upd(int idx,int l,int r,int s,int e,int op,ll v){
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		f(idx,op,v);
		res[l]=seg[idx].fi;
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le|1;
	f(le,1,seg[idx].fi);f(le,2,seg[idx].se);
	f(ri,1,seg[idx].fi);f(ri,2,seg[idx].se);
	seg[idx].fi=0;seg[idx].se=inf;
	upd(le,l,m,s,e,op,v);upd(ri,m+1,r,s,e,op,v);
}

int main(void){
	fastio;
	int n,k;
	cin>>n>>k;
	int a,b,c;ll d;
	for(int i=0;i<k;i++){
		cin>>a>>b>>c>>d;
		upd(1,0,n-1,b,c,a,d);
	}
	for(int i=0;i<n;i++){
		upd(1,0,n-1,i,i,1,0);
		cout<<res[i]<<"\n";
	}
}
