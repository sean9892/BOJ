//#define DEBUG

#ifdef DEBUG
#define TEST if(1)
#else
#define TEST if(0)
#endif

#include<bits/stdc++.h>
using namespace std;

const int nmax=200010;
int n;
int arr[nmax];
int seg[nmax<<2];
int up[nmax<<2],dw[nmax<<2];
int al[nmax<<2],ol[nmax<<2];

void init(int idx,int l,int r){
	if(l==r){
		seg[idx]=arr[l];
		up[idx]=arr[l];
		dw[idx]=~arr[l];
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);init(ri,m+1,r);
	up[idx]=up[le]&up[ri];
	dw[idx]=dw[le]&dw[ri];
	seg[idx]=max(seg[le],seg[ri]);
}

void prop(int i,int l,int r){
	seg[i]|=ol[i];
	up[i]|=ol[i];
	dw[i]-=dw[i]&ol[i];
	seg[i]&=~al[i];
	up[i]-=up[i]&al[i];
	dw[i]|=al[i];
	if(l!=r){
		for(int j:{i*2,i*2+1}){
			ol[j]&=~al[i];
			al[j]&=~ol[i];
			ol[j]|=ol[i];
			al[j]|=al[i];
		}
	}
	ol[i]=al[i]=0;
}

void ua(int idx,int l,int r,int s,int e,int x){
	TEST{
		cout<<"A "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<"\n";
	}
	prop(idx,l,r);
	if(l>e||r<s)return;
	x-=dw[idx]&x;
	if(s<=l&&r<=e&&(x&up[idx])){
		al[idx]=x&up[idx];
		x-=x&up[idx];
		prop(idx,l,r);
	}
	if(!x)return;
	int m=l+r>>1,le=idx<<1,ri=le|1;
	ua(le,l,m,s,e,x);ua(ri,m+1,r,s,e,x);
	up[idx]=up[le]&up[ri];
	dw[idx]=dw[le]&dw[ri];
	seg[idx]=max(seg[le],seg[ri]);
}

void uo(int idx,int l,int r,int s,int e,int x){
	TEST{
		cout<<"B "<<idx<<" "<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x<<"\n";
	}
	prop(idx,l,r);
	if(l>e||r<s)return;
	x-=up[idx]&x;
	if(s<=l&&r<=e&&(x&dw[idx])){
		ol[idx]=x&dw[idx];
		x-=x&dw[idx];
		prop(idx,l,r);
	}
	if(!x)return;
	int m=l+r>>1,le=idx<<1,ri=le|1;
	uo(le,l,m,s,e,x);uo(ri,m+1,r,s,e,x);
	up[idx]=up[le]&up[ri];
	dw[idx]=dw[le]&dw[ri];
	seg[idx]=max(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return -987654321;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return max(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

void pr(){
	TEST{
		cout<<"PR: ";
		for(int i=1;i<=n;i++){
			cout<<query(1,1,n,i,i)<<" ";
		}
		cout<<"\n";
	}
}

signed main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	init(1,1,n);
	pr();
	int m;
	cin>>m;
	while(m--){
		int t,l,r,x;
		cin>>t>>l>>r;
		if(t<3)cin>>x;
		if(t==1){
			ua(1,1,n,l,r,~x);
		}
		if(t==2){
			uo(1,1,n,l,r,x);
		}
		if(t==3){
			cout<<query(1,1,n,l,r)<<"\n";
		}
		pr();
	}
}
