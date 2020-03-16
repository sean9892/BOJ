#include<bits/stdc++.h>
using namespace std;

int seg[400010];

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l==r){
		seg[idx]=v;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
	seg[idx]=seg[le]+seg[ri];
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return query(le,l,m,s,e)+query(ri,m+1,r,s,e);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		upd(1,1,n,i,x&1);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t==1){
			int p,x;
			cin>>p>>x;
			upd(1,1,n,p,x&1);
		}
		if(t==2){
			int l,r;
			cin>>l>>r;
			cout<<r-l+1-query(1,1,n,l,r)<<"\n";
		}
		if(t==3){
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<"\n";
		}
	}
}
