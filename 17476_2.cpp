#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nmax = 100010;

int n;
struct node{
	int sum,lo,hi;
	node(int a=0,int b=0,int c=0):sum(a),lo(b),hi(c){}
} seg[nmax<<2];
int arr[nmax];
//lazy1[idx]*x+lazy2[idx]
int lazy1[nmax<<2];
int lazy2[nmax<<2];

int sq(int n){
	return (int)sqrt(n);
}

node f(node a,node b){
	return node(a.sum+b.sum,min(a.lo,b.lo),max(a.hi,b.hi));
}

void prop(int idx,int l,int r){
	if(lazy1[idx]==1&&lazy2[idx]==0)return;
	seg[idx].sum=seg[idx].sum*lazy1[idx]+lazy2[idx]*(r-l+1);
	seg[idx].hi=seg[idx].hi*lazy1[idx]+lazy2[idx];
	seg[idx].lo=seg[idx].lo*lazy1[idx]+lazy2[idx];
	if(l!=r){
		int le=idx<<1,ri=le+1;
		lazy1[le]*=lazy1[idx];lazy2[le]*=lazy1[idx];
		lazy1[ri]*=lazy1[idx];lazy2[ri]*=lazy1[idx];
		lazy2[le]+=lazy2[idx];
		lazy2[ri]+=lazy2[idx];
	}
	lazy1[idx]=1;lazy2[idx]=0;
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

void updsq(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		int hsq=sq(seg[idx].hi),lsq=sq(seg[idx].lo);
		if(hsq==lsq){
			lazy1[idx]=0;lazy2[idx]=hsq;
			prop(idx,l,r);
			return;
		}
		else if(seg[idx].hi-seg[idx].lo==1){
			lazy1[idx]=1;lazy2[idx]=lsq-seg[idx].lo;
            prop(idx,l,r);
			return;
		}
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	updsq(le,l,m,s,e);updsq(ri,m+1,r,s,e);
	seg[idx]=f(seg[le],seg[ri]);
}

void updpl(int idx,int l,int r,int s,int e,int x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy2[idx]=x;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	updpl(le,l,m,s,e,x);updpl(ri,m+1,r,s,e,x);
	seg[idx]=f(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx].sum;
	int m=l+r>>1;
	int le=idx<<1,ri=le+1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int32_t main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	fill(lazy1,lazy1+(nmax<<2),1);
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
			updpl(1,1,n,l,r,x);
		}
		if(t==2){
			updsq(1,1,n,l,r);
		}
		if(t==3){
			cout<<query(1,1,n,l,r)<<"\n";
		}
	}
}
