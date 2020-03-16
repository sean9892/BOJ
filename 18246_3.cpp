#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int nmax=1510;

int n,m;
int arr[1510][1510];
int s[1510][1510];

struct SEG{
	int seg[nmax<<2];
	SEG(){
		memset(seg,0,sizeof(seg));
	}
	void upd(int idx,int l,int r,int p,int v){
		if(l>p||r<p)return;
		if(l==r){
			seg[idx]=max(seg[idx],v);
			return;
		}
		int m=l+r>>1,le=idx<<1,ri=le|1;
		upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
		seg[idx]=max(seg[le],seg[ri]);
	}
	int query(int idx,int l,int r,int s,int e){
		if(l>e||r<s)return 0;
		if(s<=l&&r<=e)return seg[idx];
		int m=l+r>>1,le=idx<<1,ri=le|1;
		return max(query(le,l,m,s,e),query(ri,m+1,r,s,e));
	}
};

struct SEG2D{
	SEG seg[nmax<<2];
	SEG2D(){}
	void upd(int idx,int l,int r,int x,int y,int v){
		if(l>x||r<x)return;
		seg[idx].upd(1,0,1500,y,v);
		if(l!=r){
			int m=l+r>>1,le=idx<<1,ri=le|1;
			upd(le,l,m,x,y,v);upd(ri,m+1,r,x,y,v);
		}
	}
	int query(int idx,int l,int r,int x1,int y1,int x2,int y2){
		if(l>x2||r<x1)return 0;
		if(x1<=l&&r<=x2)return seg[idx].query(1,0,1500,y1,y2);
		int m=l+r>>1,le=idx<<1,ri=le|1;
		return max(query(le,l,m,x1,y1,x2,y2),query(ri,m+1,r,x1,y1,x2,y2));
	}
};

SEG2D seg;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		arr[a][b]++;
		arr[c][d]++;
		arr[a][d]--;
		arr[c][b]--;
	}
	for(int i=0;i<=1500;i++){
		for(int j=0;j<=1500;j++){
			s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+arr[i][j];
			seg.upd(1,0,1500,i,j,s[i+1][j+1]);
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<seg.query(1,0,1500,a,b,c-1,d-1)<<"\n";
	}
}
