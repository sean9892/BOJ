#include<bits/stdc++.h>
using namespace std;

int arr[100010];
struct node{
	int ls,rs,mx,sum;
} seg[400010];

node f(node a,node b){
	node r;
	r.ls=max(a.ls,a.sum+b.ls);
	r.rs=max(b.rs,b.sum+a.rs);
	r.mx=max({r.ls,r.rs,a.mx,b.mx,a.rs+b.ls});
	r.sum=a.sum+b.sum;
	return r;
}

void init(int idx,int l,int r){
	if(l==r){
		seg[idx].ls=seg[idx].rs=seg[idx].mx=seg[idx].sum=arr[l];
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	init(le,l,m);init(ri,m+1,r);
	seg[idx]=f(seg[le],seg[ri]);
}

node query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return {-100000,-100000,-100000,-100000};
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return f(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	init(1,1,n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		node res=query(1,1,n,l,r);
		cout<<res.mx<<"\n";
	}
}
