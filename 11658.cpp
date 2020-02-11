#include<bits/stdc++.h>
using namespace std;

const int nmax=1111;
int n;

struct SEG{
	vector<int> seg;
	SEG() : seg(nmax<<2){}
	void upd(int idx,int l,int r,int p,int v){
		if(l>p||r<p)return;
		if(l==r){
			seg[idx]+=v;
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
};

struct SEG2D{
	vector<SEG> seg;
	SEG2D() : seg(nmax<<2){}
	void upd(int idx,int l,int r,int x,int y,int v){
		if(l>x||r<x)return;
		seg[idx].upd(1,1,n,y,v);
		if(l!=r){
			int m=l+r>>1,le=idx<<1,ri=le|1;
			upd(le,l,m,x,y,v);upd(ri,m+1,r,x,y,v);
		}
	}
	int query(int idx,int l,int r,int x1,int y1,int x2,int y2){
		if(l>x2||r<x1)return 0;
		if(x1<=l&&r<=x2)return seg[idx].query(1,1,n,y1,y2);
		int m=l+r>>1,le=idx<<1,ri=le|1;
		return query(le,l,m,x1,y1,x2,y2)+query(ri,m+1,r,x1,y1,x2,y2);
	}
};

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int m;
	cin>>n>>m;
	SEG2D seg;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			seg.upd(1,1,n,j,i,x);
		}
	}
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
		if(w==0){
			int x,y,c;
			cin>>x>>y>>c;
			int q=seg.query(1,1,n,y,x,y,x);
			seg.upd(1,1,n,y,x,c-q);
		}
		if(w==1){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			cout<<seg.query(1,1,n,min(b,d),min(a,c),max(b,d),max(a,c))<<"\n";
		}
	}
}
