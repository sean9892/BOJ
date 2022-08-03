#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int nmax=100010;
int n,q;

struct node{
	ll s,e,g;
} seg[nmax<<2];
ll lazy[nmax<<2];

node mer(node a,node b){
	node r;
	r.s=a.s;r.e=b.e;
	r.g=__gcd(__gcd(a.g,b.g),__gcd(a.e,b.s));
	return r;
}

void prop(int idx,int l,int r){
	if(lazy[idx]==0)return;
	seg[idx].s+=lazy[idx];
	seg[idx].e+=lazy[idx];
	if(l!=r){
		lazy[idx<<1]+=lazy[idx];
		lazy[idx<<1|1]+=lazy[idx];
	}
	lazy[idx]=0;
}

void upd(int idx,int l,int r,int s,int e,ll v){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy[idx]=v;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,v);upd(ri,m+1,r,s,e,v);
	seg[idx]=mer(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e,node& res){
	if(l>e||r<s)return 0;
	prop(idx,l,r);
	if(s<=l&&r<=e){
		res=seg[idx];
		return 1;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le|1;
	node r1,r2;
	int q1=query(le,l,m,s,e,r1),q2=query(ri,m+1,r,s,e,r2);
	if(q1&&q2){
		res=mer(r1,r2);
		return 1;
	}
	else if(q1){
		res=r1;return 1;
	}
	else if(q2){
		res=r2;return 1;
	}
	return 0;
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		upd(1,1,n,i,i,x);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==0){
			node res;
			query(1,1,n,a,b,res);
			cout<<__gcd(res.s,res.g)<<"\n";
		}
		else{
			upd(1,1,n,a,b,t);
		}
	}
}