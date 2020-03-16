#include<bits/stdc++.h>
using namespace std;

const int lmax=1510;

struct SEG1D{
	int tree[lmax<<2];
	int lazy[lmax<<2];
	
	SEG1D(){
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
	}
	
	void prop(int idx,int l,int r){
		if(!lazy[idx])return;
		tree[idx]+=lazy[idx];
		if(l!=r){
			int le=idx<<1,ri=le|1;
			lazy[le]+=lazy[idx];
			lazy[ri]+=lazy[idx];
		}
		lazy[idx]=0;
	}
	
	void upd(int idx,int l,int r,int s,int e,int x){
		prop(idx,l,r);
		if(l>e||r<s)return;
		if(s<=l&&r<=e){
			lazy[idx]+=x;
			prop(idx,l,r);
			return;
		}
		int m=l+r>>1,le=idx<<1,ri=le|1;
		upd(le,l,m,s,e,x);upd(ri,m+1,r,s,e,x);
		tree[idx]=max(tree[le],tree[ri]);
	}
	
	int query(int idx,int l,int r,int s,int e){
		prop(idx,l,r);
		if(l>e||r<s)return 0;
		if(s<=l&&r<=e)return tree[idx];
		int m=l+r>>1,le=idx<<1,ri=le|1;
		return max(query(le,l,m,s,e),query(ri,m+1,r,s,e));
	}
};

SEG1D seg[lmax];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;j++){
			seg[j].upd(1,0,n,b,d,1);
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int r=0;
		for(int j=a;j<=c;j++){
			r=max(r,seg[j].query(1,0,n,b,d));
		}
		cout<<r<<"\n";
	}
}
