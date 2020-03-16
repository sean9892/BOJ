#include<bits/stdc++.h>
using namespace std;

int seg[100010<<2];

void upd(int idx,int l,int r,int p,int x){
	if(l>p||r<p)return;
	if(l==r){
		seg[idx]=x;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,x);upd(ri,m+1,r,p,x);
	seg[idx]=min(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0x3f3f3f3f;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return min(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		upd(1,1,n,i,x);
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<query(1,1,n,a,b)<<"\n";
	}
}
