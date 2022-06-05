#include<bits/stdc++.h>
using namespace std;
using uint=unsigned int;

const int nmax=250010;

int n,k;
uint arr[nmax];
uint seg[nmax<<2];
uint cnt[nmax<<2];

void init(int idx,int l,int r){
	if(l==r){
		seg[idx]=arr[l];
		cnt[idx]=(arr[l]==k);
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);init(ri,m+1,r);
	seg[idx]=seg[le]&seg[ri];
	cnt[idx]=cnt[le]+cnt[ri];
}

void upd(int idx,int l,int r,int s,int e,uint x){
	if(l>e||r<s)return;
	if((seg[idx]&x)==x)return;
	if(l==r){
		seg[idx]|=x;
		cnt[idx]=(seg[idx]==k);
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,x);upd(ri,m+1,r,s,e,x);
	seg[idx]=seg[le]&seg[ri];
	cnt[idx]=cnt[le]+cnt[ri];
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if((seg[idx]&k)==k&&seg[idx]!=k)return 0;
	if(s<=l&&r<=e)return cnt[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	init(1,1,n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		uint x;
		cin>>a>>b>>c;
		if(a==1){
			cin>>x;
			if(x)upd(1,1,n,b,c,x);
		}
		else{
			cout<<query(1,1,n,b,c)<<"\n";
		}
	}
}