#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nmax = 100010;

int n;

int arr[nmax];
struct node{
	int v,lo,hi;
	node(int a=0,int b=0,int c=0) : v(a),lo(b),hi(c) {}
} seg[nmax<<2];
int lazy1[nmax<<2], lazy2[nmax<<2];

int sq(int n){
	return (int)sqrt(n);
}

node f(node a,node b){
	return node(a.v+b.v,min(a.lo,b.lo),max(a.hi,b.hi));
}

void prop(int idx,int l,int r){
	if(lazy1[idx]==0&&lazy2[idx]==0)return;
	if(l!=r){
		int m=l+r>>1;
		int le=idx<<1,ri=le+1;
		prop(le,l,m);prop(ri,m+1,r);
		seg[idx]=f(seg[le],seg[ri]);
		if(lazy1[idx]){
			int hsq=sq(seg[idx].hi),lsq=sq(seg[idx].lo);
			if(hsq==lsq){
				seg[idx]=node(lsq*(r-l+1),lsq,lsq);
			}
			else if(seg[idx].hi-seg[idx].lo==1){
				seg[idx]=node(seg[idx].v+(lsq-seg[idx].lo)*(r-l+1),lsq,lsq+1);
			}
			lazy1[le]=lazy1[ri]=lazy1[idx];
			lazy1[idx]=0;
			return;
		}
		if(lazy2[idx]){
			seg[idx]=node(seg[idx].v+lazy2[idx]*(r-l+1),seg[idx].lo+lazy2[idx],seg[idx].hi+lazy2[idx]);
			lazy2[le]+=lazy2[idx];
			lazy2[ri]+=lazy2[idx];
			lazy2[idx]=0;
			return;
		}
	}
	else{
		if(lazy1[idx]){
			int s=sq(seg[idx].v);
			seg[idx]=node(s,s,s);
		}
		if(lazy2[idx])
			seg[idx]=node(seg[idx].v+lazy2[idx],seg[idx].lo+lazy2[idx],seg[idx].hi+lazy2[idx]);
		lazy1[idx]=lazy2[idx]=0;
	}
}

void init(int idx,int l,int r){
	if(l!=r){
		int m=l+r>>1;
		int le=idx<<1,ri=le+1;
		init(le,l,m);init(ri,m+1,r);
		seg[idx]=f(seg[le],seg[ri]);
		return;
	}
	seg[idx]=node(arr[l],arr[l],arr[l]);
}

void upd(int idx,int l,int r,int s,int e,int sq,int pl){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy1[idx]=sq;lazy2[idx]=pl;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	upd(le,l,m,s,e,sq,pl);
	upd(ri,m+1,r,s,e,sq,pl);
	seg[idx]=f(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx].v;
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

void print(){
	for(int i=1;i<=n;i++){
		cout<<query(1,1,n,i,i)<<" ";
	}
	cout<<"\n";
}

int32_t main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	init(1,1,n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int t,l,r,x;
		cin>>t>>l>>r;
		if(t==1){
			cin>>x;
			upd(1,1,n,l,r,0,x);
		}
		if(t==2){
			upd(1,1,n,l,r,1,0);
		}
		if(t==3){
			cout<<query(1,1,n,l,r)<<"\n";
		}
		print();
		for(int j=1;j<=n*4;j++){
			cout<<seg[j].lo<<"|"<<seg[j].hi<<" ";
		}
		cout<<"\n";
	}
}
