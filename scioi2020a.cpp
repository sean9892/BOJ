#include<bits/stdc++.h>
using namespace std;
using bit=unsigned int;

const int nmax=250010;

struct node{
	bit cu,cd;
	/*
	cu: 1인 비트는 구간 내에서 전부 1 (common up)
	cd: 1인 비트는 구간 내에서 전부 0 (common down)
	*/
};

bit k;
bit arr[nmax];
node seg[nmax<<2];
bit lazy[nmax<<2];

void init(int idx,int l,int r){
	if(l==r){
		seg[idx].cu=arr[l];
		seg[idx].cd=~arr[l];
		cout<<"X "<<idx<<" "<<l<<" "<<r<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);init(ri,m+1,r);
	seg[idx].cu=(seg[le].cu&seg[ri].cu);
	seg[idx].cd=(seg[le].cd&seg[ri].cd);
	cout<<"Y "<<idx<<" "<<l<<" "<<r<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
}

void prop(int idx,int l,int r){
	if(lazy[idx]==0)return;
	seg[idx].cu|=lazy[idx];
	seg[idx].cd&=~lazy[idx];
	if(l!=r){
		lazy[idx<<1]|=lazy[idx];
		lazy[idx<<1|1]|=lazy[idx];
	}
	lazy[idx]=0;
}

void upd(int idx,int l,int r,int s,int e,bit x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		if(l==r){
			seg[idx].cu=x;
			seg[idx].cd=~x;
			cout<<"A "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
			return;
		}
		if((seg[idx].cu|x)==seg[idx].cu){
			cout<<"B "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
			return;
		}
		lazy[idx]=x;
		prop(idx,l,r);
		cout<<"C "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,x);upd(ri,m+1,r,s,e,x);
	seg[idx].cu=(seg[le].cu&seg[ri].cu);
	seg[idx].cd=(seg[le].cd&seg[ri].cd);
	cout<<"D "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<" "<<seg[idx].cu<<" "<<seg[idx].cd<<"\n";
}

int query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s){
		cout<<"A "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<"\n";
		return 0;
	}
	if(s<=l&&r<=e){
		if(seg[idx].cu&~k){
			cout<<"B "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<"\n";
			return 0;
		}
		if(seg[idx].cd&k){
			cout<<"C "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<"\n";
			return 0;
		}
		if(seg[idx].cu==k&&seg[idx].cd==~k){
			cout<<"D "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<r-l+1<<"\n";
			return r-l+1;
		}
		if(seg[idx].cu>k){
			cout<<"E "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<"\n";
			return 0;
		}
		if(l==r){
			cout<<"F "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<"\n";
			return seg[idx].cu==k;
		}
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	int res=query(le,l,m,s,e)+query(ri,m+1,r,s,e);
	cout<<"G "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<res<<"\n";
	return res;
}

int main(void){
	//ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	init(1,1,n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"=========\n";
		int a,l,r;
		bit x;
		cin>>a>>l>>r;
		if(a==1){
			cin>>x;
			upd(1,1,n,l,r,x);
		}
		else{
			cout<<query(1,1,n,l,r)<<"\n";
		}
	}
}
