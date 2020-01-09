#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll mod=1LL<<32;
const ll nmax=500010;
ll n,q;
vector<ll> adj[nmax];
ll w[nmax],p[nmax],d[nmax];
ll in[nmax],out[nmax];
ll hld[nmax];

void dfs(ll u){
	w[u]=1;
	for(ll v:adj[u])if(!w[v]){
		p[v]=u;
		d[v]=d[u]+1;
		dfs(v);
		w[u]+=w[v];
	}
}

ll cnt=0;
void dfs2(ll u){
	ll cc=-1;
	in[u]=++cnt;
	for(ll v:adj[u])if(p[v]==u&&(cc==-1||w[v]>w[cc]))cc=v;
	if(cc!=-1){
		hld[cc]=hld[u];dfs2(cc);
	}
	for(ll v:adj[u])if(p[v]==u&&v!=cc){
		hld[v]=v;dfs2(v);
	}
	out[u]=cnt;
}

const ll trsz=nmax<<2;
ll seg[trsz];
ll lazy1[trsz],lazy2[trsz];

void prop(ll idx,ll l,ll r){
	if(lazy1[idx]==1&&lazy2[idx]==0)return;
	seg[idx]*=lazy1[idx];
	seg[idx]+=lazy2[idx]*(r-l+1);
	seg[idx]%=mod;
	if(l!=r){
		ll le=idx<<1,ri=le+1;
		lazy1[le]*=lazy1[idx];lazy2[le]*=lazy1[idx];lazy2[le]+=lazy2[idx];
		lazy1[ri]*=lazy1[idx];lazy2[ri]*=lazy1[idx];lazy2[ri]+=lazy2[idx];
		lazy1[le]%=mod;lazy2[le]%=mod;
		lazy1[ri]%=mod;lazy2[ri]%=mod;
	}
	lazy1[idx]=1;lazy2[idx]=0;
}

void updpl(ll idx,ll l,ll r,ll s,ll e,ll x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=1;lazy2[idx]=x;
		prop(idx,l,r);
		return;
	}
	ll m=l+r>>1,le=idx<<1,ri=le+1;
	updpl(le,l,m,s,e,x);updpl(ri,m+1,r,s,e,x);
	seg[idx]=(seg[le]+seg[ri])%mod;
}

void updml(ll idx,ll l,ll r,ll s,ll e,ll x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=x;lazy2[idx]=0;
		prop(idx,l,r);
		return;
	}
	ll m=l+r>>1,le=idx<<1,ri=le+1;
	updml(le,l,m,s,e,x);updml(ri,m+1,r,s,e,x);
	seg[idx]=(seg[le]+seg[ri])%mod;
}

ll squ(ll idx,ll l,ll r,ll s,ll e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	ll m=l+r>>1,le=idx<<1,ri=le+1;
	return (squ(le,l,m,s,e)+squ(ri,m+1,r,s,e))%mod;
}

void adds(ll x,ll v){
	updpl(1,1,n,in[x],out[x],v);
}

void addp(ll x,ll y,ll v){
	while(hld[x]!=hld[y]){
		if(d[x]>d[y])swap(x,y);
		updpl(1,1,n,in[hld[y]],in[y],v);
		y=p[hld[y]];
	}
	if(d[x]>d[y])swap(x,y);
	updpl(1,1,n,in[x],in[y],v);
}

void muls(ll x,ll v){
	updml(1,1,n,in[x],out[x],v);
}

void mulp(ll x,ll y,ll v){
	while(hld[x]!=hld[y]){
		if(d[x]>d[y])swap(x,y);
		updml(1,1,n,in[hld[y]],in[y],v);
		y=p[hld[y]];
	}
	if(d[x]>d[y])swap(x,y);
	updml(1,1,n,in[x],in[y],v);
}

void qus(ll x){
	cout<<squ(1,1,n,in[x],out[x])<<"\n";
}

void qup(ll x,ll y){
	ll sum=0;
	while(hld[x]!=hld[y]){
		if(d[x]>d[y])swap(x,y);
		sum+=squ(1,1,n,in[hld[y]],in[y]);
		sum%=mod;
		y=p[hld[y]];
	}
	if(d[x]>d[y])swap(x,y);
	sum+=squ(1,1,n,in[x],in[y]);
	sum%=mod;
	cout<<sum<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	fill(lazy1,lazy1+trsz,1);
	fill(lazy2,lazy2+trsz,0);
	hld[1]=1;
	cin>>n>>q;
	for(ll i=1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);dfs2(1);
	for(ll i=0;i<q;i++){
		ll t,x,y;
		ll v;
		cin>>t;
		if(t==1){
			cin>>x>>v;
			adds(x,v);
		}
		if(t==2){
			cin>>x>>y>>v;
			addp(x,y,v);
		}
		if(t==3){
			cin>>x>>v;
			muls(x,v);
		}
		if(t==4){
			cin>>x>>y>>v;
			mulp(x,y,v);
		}
		if(t==5){
			cin>>x;
			qus(x);
		}
		if(t==6){
			cin>>x>>y;
			qup(x,y);
		}
	}
}
